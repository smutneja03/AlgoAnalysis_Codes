
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *array, int start, int mid, int end){

  int temp[end];
  int i = start, j = mid + 1, k = 0;
  
  while (i <= mid && j <= end){

    if (array[i] <= array[j])
      temp[k++] = array[i++];
    
    else
      temp[k++] = array[j++];
    
    }
    
    while (i <= mid)
        temp[k++] = array[i++];
  
    while (j <= end)
        temp[k++] = array[j++];
  
    k--;

    while (k >= 0) {
        array[start + k] = temp[k];
        k--;
    }

}

void merge_sort(int *array, int start, int end){

  int mid;

  if(start<end){

    mid = (start+end)/2;
    merge_sort(array, start, mid);
    merge_sort(array, mid+1, end);

    merge(array, start, mid, end);
  }

}

int main(int argc, char *argv[]){

	FILE *log_average = fopen("log_merge_average.txt", "a");
	FILE *log_best = fopen("log_merge_best.txt", "a");
	FILE *log_worst = fopen("log_merge_worst.txt", "a");

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
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = rand() % input_size;
  	
  	}


  	//beginning with the internal time counter
  	begin = clock();

  	merge_sort(array, 0, input_size-1);//calling the merge sort function for sorting the array
  	//ending with the internal time counter
  	end = clock();


  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


  	fprintf(log_average, "%d %lf\n", input_size, time_spent);


  	//generating numbers in an ascending order and storing them in the array
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = j;
  	
  	}
  	

  	begin = clock();

    merge_sort(array, 0, input_size-1);

  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	fprintf(log_best, "%d %lf\n", input_size, time_spent);

    //The best case input is an array that is already sorted. In this case merge sort has a linear running time (i.e., Θ(n)). 
  	//generating numbers in an descending order and storing them in the array
  	int i = 0;
    for (j = input_size-1; j >= 0; j--){
  		//will store in the array numbers in a random order equal to the input size
  		array[i++] = j;
  	
  	}
  	

  	begin = clock();
  	
    merge_sort(array, 0, input_size-1);
  	
  	//ending with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  	fprintf(log_worst, "%d %lf\n", input_size, time_spent);

    //The simplest worst case input is an array sorted in reverse order.
    //This gives merge sort a quadratic running time (i.e., O(n2)).
}


