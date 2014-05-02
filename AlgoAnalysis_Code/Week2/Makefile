
#the given makefile compiles the main BST C file, 
#erases the random numbers and then rewrites those numbers

all : assgn2 infile rand inorder

assgn2 : assgn2.c
	gcc -g -o assgn2 assgn2.c

infile : infile.txt
	>infile.txt

rand : rand.py
	python rand.py 

inorder : inorder.txt
	>inorder.txt

#will be done separately to run python script to check the correctness of the code
check : check_result.py
	python check_result.py

clear : test_results.txt
	>test_results.txt