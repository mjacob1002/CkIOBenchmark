import os
import sys
import argparse


def main():
	print("This is an infrastructure script\n")
	parser = argparse.ArgumentParser(prog="run_experiment.py",
					 description = "run an experiment",
					 epilog="Epilog text"
					 )
	parser.add_argument("--nodes", nargs=1, type=int, required=True, help="number of nodes to run in the experiment") # get the number of nodes to run the experiment
	parser.add_argument("--ppn", type=int, nargs=1, required=True, help="The number of cores to request per node")
	parser.add_argument("--io_type", dest="io_type", choices=["CkIO", "MPI", "Charm-Naive"], required=True, help="Choosing whether to use MPI IO or CkIO")
	parser.add_argument("--num_readers", dest="num_readers", type=int, help="Choosing the number of total readers for the benchmark.")
	parser.add_argument("--io_pattern", dest="pattern", choices=["cyclic", "block"], required=True, help="Choose between a cyclic or flat read pattern")
	parser.add_argument("--dir", dest="dir", nargs=1, required=True, help="The directory to store the results")
	parser.add_argument("--output_file", dest="out_file", nargs=1, required=True, help="The name of the file where the output should be stored\n")
	parser.add_argument("--dump_file", dest="dump", nargs=1, type=str, required=True, help="The name of the dump file the experiment will write it's metrics of the experiment to.\n")
	parser.add_argument("--num_io_buffers", dest="buffer_chares", nargs=1, type=int, help="the number of I/O buffer chares for the CkIO experiment\n")
	parser.add_argument("--work_queue", dest="queue", nargs=1, type=str, help="the queue you want it to go to")
	parser.add_argument("--input_file", dest="ifile", nargs=1, type=str, help="The input file to be read\n")
	args = parser.parse_args()
	print((args.nodes))
	print(args.ppn)
	print(args.io_type)
	print(args.num_readers)
	print(args.pattern)
	print(args.dir)
	print(args.out_file)
	num_pes = args.nodes[0] * args.ppn[0]
	print(num_pes)
	command = "" 
	# do cases on the type of input
	if (args.io_type == "CkIO"):
		num_buffers = int(args.buffer_chares[0])
		executable = "../iotest"
		charmrun = "../charmrun"
		command = f"{charmrun} +p{num_pes} {executable} {args.ifile[0]} {num_pes} {num_buffers} {args.num_readers} {args.dump[0]}\n"

		if args.pattern == "cyclic":
			executable = "../cyclic_reads/cyclic_test"
			charmrun = "../cyclic_reads/charmrun"
			chunk = 64 * 1024 * 1024
			command = f"{charmrun} +p{num_pes} {executable} {args.ifile[0]} {num_pes} {num_buffers} {args.num_readers} {chunk} {args.dump[0]}\n"
	elif (args.io_type == "MPI") and args.pattern == "cyclic":
		command = f"ibrun -np {num_pes} ../MPI_Cyclic/mpi_io.exe {args.ifile[0]}\n"
	
	else:
		num_buffers = int(args.buffer_chares[0])
		if args.pattern == "block":
			command = f"../charmrun +p{num_pes} ../naive {args.ifile[0]} {num_pes} {num_buffers} {args.num_readers} {args.dump[0]}\n"
	writeSBATCH(args.nodes[0], args.ppn[0], args.dir[0], args.out_file[0], command, args.queue[0])
 

def writeSBATCH(nodes, ppn, directory, ofile, command, queue):
	print("currently writing the stuff for the sbatch file\n")
	dir_exists = os.path.exists(directory)
	if not dir_exists:
		os.makedirs(directory)
		print("constructed directory ", directory)
	print("The command is as follows: ", command)
	out_loc = directory + "/" + ofile
	f = open("slurm_script", "w")
	f.write("#!/bin/bash\n")
	sbatch = "#SBATCH "
	f.write(f"{sbatch} --nodes={nodes}\n") # write the number of nodes
	f.write(f"{sbatch} --ntasks-per-node={ppn}\n")
	f.write(f"{sbatch} --output={out_loc}\n")
	f.write(f"{sbatch} --job-name={ofile}\n")
	f.write(f"{sbatch} --time=00:07:30\n")
	f.write(f"{sbatch} --dependency=singleton\n")
	f.write(f"{sbatch} -p {queue}\n")
	f.write(command) # write the command

main()
