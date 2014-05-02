
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* A typical recursive implementation of quick sort */

// A utility function to swap two elements
void swap ( int* a, int* b ){

    int t = *a;
    *a = *b;
    *b = t;
} 

/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int l, int h){

    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1);
}
 
/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quick_sort(int A[], int l, int h){

    if (l < h)
    {        
        int p = partition(A, l, h); /* Partitioning index */
        quick_sort(A, l, p - 1);  
        quick_sort(A, p + 1, h);
    }
}
/*
In early versions of Quick Sort where leftmost (or rightmost) element is chosen as pivot, the worst occurs in following cases.

1) Array is already sorted in same order.
2) Array is already sorted in reverse order.
3) All elements are same (special case of case 1 and 2)

Since these cases are very common use cases, the problem was easily solved by choosing either 
a random index for the pivot, choosing the middle index of the partition or (especially for 
longer partitions) choosing the median of the first, middle and last element of the partition for the pivot.
With these modifications, the worst case of Quick sort has less chances to occur, but worst case 
can still occur if the input array is such that the maximum (or minimum) element is always chosen
as pivot.
*/
  

int main(int argc, char *argv[]){

	FILE *log_average = fopen("log_quick_average.txt", "a");
	FILE *log_best = fopen("log_quick_best.txt", "a");
	FILE *log_worst = fopen("log_quick_worst.txt", "a");

	//used for calculating time within the function used for searching the element
	clock_t begin, end;
	double time_spent;

	int input_size;

	if(log_average==NULL || log_best==NULL || log_worst==NULL){

		printf("Error in opening of the log text files\n");
		return 0;
	}

	if(argc < 2){
		//missing number of arguments
		printf("Error : enter the value of n as an argument\n");
		return 0;
	}

	if(argv[1] != NULL){
				
		input_size = atoi(argv[1]);//now we have the input size for the array
		
	}


	//allocating dyanamic memory for the array in question
	//this step will be the same for all the three cases to be taken care of
	//memory equal to the size of the input size is assigned

  int array[input_size];

	//Reporting error if any
	if(!array){
  		fputs("Memory allocation failed.\n", stderr);
  		exit(EXIT_FAILURE);
  	}

  	//need to generate numbers in an random order, ascending order and in the descending order

  	//generating numbers in an random order and storing them in the array
  	int j;
  	
    //generating numbers in an ascending order and storing them in the array
    for (j = 0; j < input_size; j++){
      //will store in the array numbers in a random order equal to the input size
      array[j] = j;
    
    }
    

    begin = clock();

    quick_sort(array, 0, input_size-1);

    end = clock();


    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(log_worst, "%d %lf\n", input_size, time_spent);

    for (j = 0; j < input_size; j++){
      //will store in the array numbers in a random order equal to the input size
      array[j] = rand() % input_size;
    
    }


    //beginning with the internal time counter
    begin = clock();

    quick_sort(array, 0, input_size-1);//calling the quick sort function for sorting the array
    //ending with the internal time counter
    end = clock();


    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


    fprintf(log_average, "%d %lf\n", input_size, time_spent);

  	
}


