import os
import sys

#num_nodes = 5
#cores_per_node = 128
#pes = num_nodes * cores_per_node 
#SBATCH = "#SBATCH "
#job = SBATCH + "--job-name "
#nodes = SBATCH + "--nodes="
#ntasks = SBATCH + "--ntasks="
#ntpn = SBATCH + "--ntasks-per-node=1"
#time = SBATCH + "-t 00:10:00"
#email = SBATCH + "--mail-user=mjacob1002@gmail.com"
#begin = SBATCH + "--mail-type=BEGIN"
#end = SBATCH + "--mail-type=END"
#
#for i in range(20, 33):
#   filename = str(i) + ".txt" # the file to use
#   environment = "module load openmpi/4.0.5-gcc10.2.0"
#   command = "./charmrun +p" + str(pes) + " ./iotest TEST_FILES/" + str(i) + ".txt"
#   f = open("slurm_test", "w")
#   f.write("#!/bin/bash\n")
#   f.write(job + str(i) + "\n")
#   f.write(nodes + str(num_nodes) + "\n")
#   f.write(ntasks + str(num_nodes) + "\n")
#   f.write(ntpn + "\n")
#   f.write(time + "\n")
#   f.write(SBATCH + " --output=" + str(i) + "benchmark.out\n")
#   f.write(email+"\n")
#   f.write(begin + "\n")
#   f.write(end + "\n")
#   f.write(environment + "\n")
#   f.write(command)
#   f.close()
#   os.system("sbatch slurm_test")
#

MPI_PROGRAM = "MPIstuff/mpi_io" 
BASE_RES_DIR = "STRONG_SCALING_WHOLE_PROGRAM_MPI/"
def strong_scaling(max_num_nodes, max_file_exp, mpi: bool):
	file_size = 30 
	while file_size <= max_file_exp:
		if not os.path.isdir( BASE_RES_DIR+ str(file_size)):
		    os.makedirs(BASE_RES_DIR + str(file_size))
		for num_nodes in range(1, max_num_nodes + 1):
		    strong_scaling_single_experiment(num_nodes, file_size, BASE_RES_DIR + str(file_size), mpi)
		file_size += 1 

def writeBoilerPlate(slurm_script_fname, output_filename, job_name, num_nodes, ntasks_per_node, time, commands, queue=None):
	SBATCH = "#SBATCH "
	job = SBATCH + "--job-name "
	nodes = SBATCH + "--nodes="
	ntpn = SBATCH + "--ntasks-per-node=" + str(ntasks_per_node)
	time = SBATCH + "-t 00:15:00"
	email = SBATCH + "--mail-user=mjacob1002@gmail.com"
	begin = SBATCH + "--mail-type=BEGIN"
	end = SBATCH + "--mail-type=END"
	f = open(slurm_script_fname, "w")
	f.write("#!/bin/bash\n")
	f.write(job + job_name + "\n") 
	if queue is not None:
		f.write(SBATCH + "-p " + queue + "\n") # if specified, add the queue
	f.write(nodes + str(num_nodes) + "\n")
	f.write(ntpn + "\n")
	f.write(SBATCH + "--output=" + output_filename + "\n")
	f.write(time + "\n")
	f.write(begin + "\n")
	f.write(end + "\n")
	f.write(SBATCH + " --exclusive\n")
	for command in commands:
		f.write(command + "\n")
	f.close()		

disk_read_directory = "DISK_READ_EXPERIMENTS/"
def findOptimalDiskReads(number_nodes, file_size, input_queue=None):
	number_pes_per_node = 32
	size_in_mb = 7 # 2^10 MBS
	disk_read_dir = disk_read_directory	
	if not os.path.isdir(disk_read_dir + str(file_size)):
		os.makedirs(disk_read_dir + str(file_size))
	

	while size_in_mb < 8: # will try buffers storing from 8MB to 2GB
		slurm_script_name = "slurm_testing_diskread_size"
		pes = number_pes_per_node * number_nodes
		fname = str(number_nodes) + "_" + str(file_size) + "_" + str(size_in_mb) + ".out"
		output_fname = disk_read_directory + str(file_size) + "/" + fname 
		time = "00:10:00"
		compiler_load = "module load gcc/9.1.0"
		execute_driver = "./charmrun +p" + str(pes) + " ./iotest TEST_FILES/" + str(file_size) + ".txt " + str(pes) + " " + str(size_in_mb) 
		commands = [compiler_load, execute_driver]
		job_name = str(size_in_mb) + "_diskreads"
		writeBoilerPlate(slurm_script_name, output_fname, job_name, number_nodes, number_pes_per_node, time, commands, queue=input_queue)
		# os.system("sbatch " + slurm_script_name)
		size_in_mb += 1
		


# CkIO strong scaling
def strong_scaling_single_experiment(num_nodes, file_size, directory, queue=None, mpi=False):
	cores_per_node = 32 
	pes = num_nodes * cores_per_node 
#     SBATCH = "#SBATCH "
#     job = SBATCH + "--job-name "
#     nodes = SBATCH + "--nodes="
#     ntasks = SBATCH + "--ntasks="
#     ntpn = SBATCH + "--ntasks-per-node=" + str(cores_per_node)
#     time = SBATCH + "-t 00:15:00"
#     email = SBATCH + "--mail-user=mjacob1002@gmail.com"
#     begin = SBATCH + "--mail-type=BEGIN"
#     end = SBATCH + "--mail-type=END"
# 
	filename = directory + "/" + str(file_size) + "_" + str(num_nodes) + ".txt" # the file to open to put the output
	environment = "module load openmpi/4.0.5-gcc10.2.0"
	command = "./charmrun +p" + str(pes) + " ./iotest TEST_FILES/" + str(file_size) + ".txt " + str(pes)
	if mpi:
		command = "mpirun -np " + str(pes) + " " + MPI_PROGRAM + " TEST_FILES/" + str(file_size) + ".txt "
	
#    f = open("slurm_test", "w")
#    f.write("#!/bin/bash\n")
#    f.write(job + str(file_size) + "_" + str(num_nodes) + "\n")
#    f.write(nodes + str(num_nodes) + "\n")
#    f.write(ntasks + str(num_nodes) + "\n")
#    f.write(ntpn + "\n")
#    f.write(time + "\n")
#    if mpi:
#        f.write(SBATCH + " --output=" + directory + "/mpi_" + str(file_size) + "_" + str(num_nodes) + "_benchmark.out\n") # {FILESIZE}_{NUM_NODES}_benchmark.out
#    else:
#        f.write(SBATCH + " --output=" + directory + "/" + str(file_size) + "_" + str(num_nodes) + "_benchmark.out\n") # {FILESIZE}_{NUM_NODES}_benchmark.out
#    f.write(email+"\n")
#    f.write(begin + "\n")
#    f.write(end + "\n")
#    f.write(environment + "\n")
#    f.write(command)
	jobname = str(file_size) + "_" + str(num_nodes)
	ntasks_per_node = cores_per_node
	time = "00:10:00"
	writeBoilerPlate("slurm_script_test",filename,jobname, num_nodes, ntasks_per_node, time, [environment, command], queue) 

# strong_scaling(20, 40, True)

# strong_scaling_single_experiment(5, 36, "TEST_OUTPUT_DIR", queue="skx-normal", mpi=False)
findOptimalDiskReads(6, 35,"skx-normal") # (number of nodes, file size)
# strong_scaling_single_experiment(6, 36, BASE_RES_DIR, queue="skx-normal", mpi=True)
