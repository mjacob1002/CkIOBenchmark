import os
import sys
import numpy as np
from matplotlib import pyplot as plt

# if __name___ == '__main__':
#     main()

# give the beginning of the directory to generate plots for
def readOutputFilesize(filesize: int, start_node: int, end_node: int, dir_of_choice: str):
    nodes = []
    times = []

    for num_nodes in range(start_node, end_node + 1):
        filename = dir_of_choice + str(filesize) + "/" + str(filesize) + "_" + str(num_nodes) + "_benchmark.out"
        try:
            f = open(filename, "r")
        except IOError:
            print(filename, " couldn't be opened because it didn't exist")
            continue
        for line in f:
            if len(line) <= len("Total time:"):
                continue
            tokens = line.split()
            if tokens[0] != "Total" or tokens[1] != "time:":
                continue
            time = float(tokens[2])
            times.append(time) # append the time found
            nodes.append(num_nodes) # append the number of nodes used
            break

    return np.array(nodes), np.array(times)


def readDiskReadData(filesize: int, num_node: int, dir_of_choice: str):
    nodes = []
    times = []

    for num_nodes in range(start_node, end_node + 1):
       	filename = dir_of_choice + str(filesize) + "/" + str(filesize) + "_" + str(num_nodes) + "_benchmark.out"
        try:
            f = open(filename, "r")
        except IOError:
            print(filename, " couldn't be opened because it didn't exist")
            continue
        for line in f:
            if len(line) <= len("Total time:"):
                continue
            tokens = line.split()
            if tokens[0] != "Total" or tokens[1] != "time:":
                continue
            time = float(tokens[2])
            times.append(time) # append the time found
            nodes.append(num_nodes) # append the number of nodes used
            break

    return np.array(nodes), np.array(times)

# start_node and end_node are inclusive
def plotFilesizeConstant(filesize: int, start_node:int , end_node:int, dir_of_choice: str ):
    nodes, times = readOutputFilesize(filesize, start_node, end_node, dir_of_choice)
    bandwidths = np.zeros(len(times))
    num_gigabytes = 2 ** (filesize - 30)
    for i in range(len(nodes)):
        bandwidths[i] = float(num_gigabytes / times[i])
    plt.plot(nodes, bandwidths, marker="p")
    plt.xlabel("Number of Nodes")
    plt.ylabel("Read speed in GiB/sec")
    plt.title("Number of Nodes vs Bandwidth of Reads for " + str(filesize) + " GiB files")
    plt.savefig(dir_of_choice + "plots/" + str(filesize) + "_plot.png")
    plt.clf()
    print("plot created for ", filesize)



dir_choice = "STRONG_SCALING_WHOLE_PROGRAM_MPI/"
nodes, times = readOutputFilesize(30, 1, 20, dir_choice)
print(nodes)
print(times)


for i in range(30, 41):
    plotFilesizeConstant(i, 1, 20, dir_choice)

