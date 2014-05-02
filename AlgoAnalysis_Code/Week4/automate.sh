
#!/usr/bash

#this script will run a loop which will perform the following functions
#run a loop via a increment of 1000 from 1 to 500,000
#under each iteration, operation on the data structures will be performed 
#the operation will generate time vs the input size 

gcc -g -o insertion_sort insertion_sort.c
gcc -g -o merge_sort merge_sort.c
gcc -g -o quick_sort quick_sort.c
gcc -g -o count_sort count_sort.c
gcc -g -o heap_sort heap_sort.c

#>log_insertion_average.txt
#>log_insertion_best.txt
#>log_insertion_worst.txt

#>log_merge_average.txt
#>log_merge_best.txt
#>log_merge_worst.txt

#>log_quick_average.txt
>log_quick_best.txt
#>log_quick_worst.txt

#>log_count_average.txt
#>log_count_best.txt
#>log_count_worst.txt

#>log_heap_average.txt
#>log_heap_best.txt
#>log_heap_worst.txt



for (( i=1; i<=500001;i+=1000 ))
	do
		./quicksort_best $i
		
	done


