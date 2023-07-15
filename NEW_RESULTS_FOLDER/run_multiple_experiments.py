import os
import sys
import argparse
from time import sleep

def main():
	out_file = "outCkIO_"
	# temp_nodes = [4,8,16,32,64]
	temp_nodes = [8,16,32,64]
	scaling_buffer_factors = [0.5, 1, 2, 4]
	for num_nodes in temp_nodes:
		num_cores = 48 * num_nodes
		buffers = [num_cores*i for i in scaling_buffer_factors] # sweep testing of 1,2,3 or 4 I/O buffers per PE
		for num_buffers in buffers:
			num_buffers = int(num_buffers)
			print(type(num_buffers))
			num_readers = 2 * num_cores# number of readers per PE
			dump_file = "NEWDIRECTORY/MULTI_CHARE_CkIO/testCkIO_" + str(num_nodes) + "_" + str(num_readers) + "_" + str(num_buffers)
			# output_file = out_file + str(num_nodes) + "_" + str(num_readers)
			output_file = "testNaive"
			command = f"python3 run_experiment.py --nodes={num_nodes} --ppn=48 --io_type=CkIO --num_readers={num_readers} --io_pattern=block --dir=NEWDIRECTORY/MULTI_CHARE_CkIO --output_file={output_file} --num_io_buffers={num_buffers} --work_queue=skx-normal --input_file=$SCRATCH/TEST_FILES/128.txt --dump_file={dump_file}"# .format(number_nodes=num_nodes, cores=num_cores, readers=num_readers, out=output_file, io_buffers=num_readers, dump=dump_file) 
			print(f"The number of nodes={num_nodes}, output_file={output_file}, command={command}")
			print(command)
			os.system(command)
			for i in range(3):
				os.system("sbatch slurm_script")

main()
