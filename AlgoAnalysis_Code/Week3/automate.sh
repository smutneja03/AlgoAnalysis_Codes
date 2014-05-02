
#!/usr/bash

#this script will run a loop which will perform the following functions
#run a loop via a increment of 1000 from 1 to 500,000
#under each iteration, operation on the data structures will be performed 
#the operation will generate time vs the input size 

gcc -g -o array array.c
gcc -g -o bst bst.c
gcc -g -o balanced_bst balanced_bst.c
gcc -g -o array_sorted array_sorted.c

#>log_array_random.txt; >log_array_asc.txt; >log_array_desc.txt

#>log_bst_random.txt
#>log_bst_asc.txt 
#>log_bst_desc.txt

>log_balanced_bst_random.txt 
>log_balanced_bst_asc.txt 
>log_balanced_bst_desc.txt

#>log_sarray.txt

#for (( i=175001; i<=300001;i+=1000 ))
#	do
#		./bst $i
#
#	done

#for (( i=1; i<=500001;i+=1000 ))
#	do
#		./array $i
#
#	done

#for (( i=1; i<=500001;i+=1000 ))
#	do
#		./array_sorted $i

#	done
	
for (( i=1; i<=500001;i+=1000 ))
	do
		./balanced_bst $i

	done

