import sys
sys.setrecursionlimit(1000000000)

# N is the number of keys in the sequence.
N = None

# P contains the sequence of keys.
P = []

answer = None

# Open the input and output files.
input_file = open("compin.txt", "r")
output_file = open("compout.txt", "w")

N = int(input_file.readline().strip())

input_line = input_file.readline().strip()
P = list(map(int, input_line.split()))











# Write the answer to the output file.
output_file.write("%d\n" % (answer))

# Finally, close the input/output files.
input_file.close()
output_file.close()