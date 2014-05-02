
#	Comments
#	the given program will check whether all the values written into the inorder.txt file are in sorted order or not
#	the file this program will be reading from is inorder.txt
#	Author : Sahil Mutneja
#	Dated : 28th February 2014	

#pointer to the file containing the contents of the inorder traversal of the BST
file_handle = open("inorder.txt", "r")

lines = [int(line.strip()) for line in file_handle]
#lines array contains the list version of all the values present in the file
#checks whether the inorder traversal is in sorted order or not
if lines == sorted(lines):
	print "Correct Solution"
else :
	print "Incorect Approach"

file_handle.close()
