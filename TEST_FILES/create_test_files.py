import os
import sys
import subprocess

for i in range(36, 43):
   num_bytes = 2**i
   filename = str(i) + str(".txt")
   command = "truncate -s " + str(num_bytes) + " " + filename
   os.system(command)

