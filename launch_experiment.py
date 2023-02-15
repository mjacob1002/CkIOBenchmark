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

# CkIO strong scaling
def strong_scaling_single_experiment(num_nodes, file_size, directory, mpi: bool):
    cores_per_node = 128
    pes = num_nodes * cores_per_node 
    SBATCH = "#SBATCH "
    job = SBATCH + "--job-name "
    nodes = SBATCH + "--nodes="
    ntasks = SBATCH + "--ntasks="
    ntpn = SBATCH + "--ntasks-per-node=" + str(cores_per_node)
    time = SBATCH + "-t 00:15:00"
    email = SBATCH + "--mail-user=mjacob1002@gmail.com"
    begin = SBATCH + "--mail-type=BEGIN"
    end = SBATCH + "--mail-type=END"

    filename = directory + "/" + str(file_size) + "_" + str(num_nodes) + ".txt" # the file to use
    environment = "module load openmpi/4.0.5-gcc10.2.0"
    command = "./charmrun +p" + str(pes) + " ./iotest TEST_FILES/" + str(file_size) + ".txt " + str(pes)
    if mpi:
        command = "mpirun -np " + str(pes) + " " + MPI_PROGRAM + " TEST_FILES/" + str(file_size) + ".txt "
    f = open("slurm_test", "w")
    f.write("#!/bin/bash\n")
    f.write(job + str(file_size) + "_" + str(num_nodes) + "\n")
    f.write(nodes + str(num_nodes) + "\n")
    f.write(ntasks + str(num_nodes) + "\n")
    f.write(ntpn + "\n")
    f.write(time + "\n")
    if mpi:
        f.write(SBATCH + " --output=" + directory + "/mpi_" + str(file_size) + "_" + str(num_nodes) + "_benchmark.out\n") # {FILESIZE}_{NUM_NODES}_benchmark.out
    else:
        f.write(SBATCH + " --output=" + directory + "/" + str(file_size) + "_" + str(num_nodes) + "_benchmark.out\n") # {FILESIZE}_{NUM_NODES}_benchmark.out
    f.write(email+"\n")
    f.write(begin + "\n")
    f.write(end + "\n")
    f.write(environment + "\n")
    f.write(command)
    f.close()
    os.system("sbatch slurm_test")

strong_scaling(20, 40, True)
