#!/usr/bin/env python
import sys
sys.setrecursionlimit(1000000000)

#
# Solution Template for Wheeling and Dealing
# 
# Australian Informatics Olympiad 2023
# 
# This file is provided to assist with reading and writing of the input
# files for the problem. You may modify this file however you wish, or
# you may choose not to use this file at all.
#

# N is the number of candidates.
N = None

# M is the number of voters.
M = None

# V contains the voters plans. Note that here the voters are numbered starting
# from 0.
V = []

# P contains the amount of money that you can pay each voter to change their
# vote. Note that here the voters are numbered starting from 0.
P = []

# Open the input and output files.
input_file = open("dealin.txt", "r")
output_file = open("dealout.txt", "w")

# Read the values of N, M, V and P from input file.
input_line = input_file.readline().strip()
N, M = map(int, input_line.split())
input_line = input_file.readline().strip()
V = list(map(int, input_line.split()))
input_line = input_file.readline().strip()
P = list(map(int, input_line.split()))

cani = []
voter = []

for i, val in enumerate(P):
    voter[i] = val

answer = 0

sorted(voter)

for i, v in enumerate(voter):
    voter[i]++;

for v in voter:
    


# Write the answers to the output file.
output_file.write("%d\n" % (answer))

# Finally, close the input/output files.
input_file.close()
output_file.close()
