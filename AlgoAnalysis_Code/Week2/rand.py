
#	Comments
#	the given program will write random numbers into a text file which will then be entered into the BST
#	the file this program will be writing to is infile.txt
#	Author : Sahil Mutneja
#	Dated : 28th February 2014	

import random

file_handle = open("infile.txt", "w")

for i in range(1, 100):
	line = str(random.randint(1, 1000))
	file_handle.write(line + "\n")

file_handle.close()
