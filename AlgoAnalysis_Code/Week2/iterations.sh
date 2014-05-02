
#!/usr/bash

#this script will run a loop which will perform the following functions
#run the random number script
#run the program and output the sorted order into inorder.txt
#run python script to check the inorder.txt file to be in sorted order or not 

for i in {1..100}
do
	>infile.txt #will clear the current content of the random numbers
	python rand.py #will print random numbers into the file infile.txt
	>inorder.txt #will clear the contents of the file inorder.txt 
	./assgn2 infile.txt >> /dev/null #this will output the inorder traversal in the file inorder.txt 
	python check_result.py >> test_results.txt #will check for the sorted order and then ouput the answer to the test_results file
done

