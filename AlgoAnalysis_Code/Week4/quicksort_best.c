
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Prototypes */
void swap(int[], int, int);

/* Declarations */

void display(int array[], int length)
{
	int i;
	printf(">");
	for (i = 0; i < length; i++)
		printf(" %d", array[i]);
	printf("\n");
}

int partition(int array[], int left, int right, int pivot_index)
{
	int pivot_value = array[pivot_index];
	int store_index = left;
	int i = left;
	int j = right-1;
	while (1) {
   		while (array[++i] < pivot_value) { }  // move i up and keep going if element is < pivot
 
   		while (pivot_value < array[--j]) { }  // move j down and keep going if element is > pivot
 
   		if (i < j) {
      		swap(array, i, j);
   		} 
   		else {
      		break;
   		}
	}
	return i;

	//swap(array, pivot_index, right);
	//for (i = left; i < right; i++)
	//	if (array[i] <= pivot_value) {
	//		swap(array, i, store_index);
	//		++store_index;
	//	}
	//swap(array, store_index, right);
	//return store_index;
}

void quicksort(int array[], int left, int right)
{
	int pivot_index = (left+right)/2;
	int pivot_new_index;

	/*
	printf("sorting %d to %d\n", left, right);
	*/
	if (right > left) {
		pivot_new_index = partition(array, left, right, pivot_index);
		quicksort(array, left, pivot_new_index - 1);
		quicksort(array, pivot_new_index + 1, right);
	}
}

void swap(int array[], int left, int right)
{
	int temp;
	temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

int main(int argc, char *argv[]){
	
	FILE *log_best = fopen("log_quick_best.txt", "a");

	//used for calculating time within the function used for searching the element
	clock_t begin, end;
	double time_spent;

	int input_size;

	if(log_best==NULL){

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

    quicksort(array, 0, input_size-1);

    end = clock();


    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(log_best, "%d %lf\n", input_size, time_spent);

}


	