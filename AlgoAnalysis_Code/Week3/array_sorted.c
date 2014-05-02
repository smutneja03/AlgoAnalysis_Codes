
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search(int element, int array[], int start, int end){

	int middle = (start+end)/2;

	if(start==end){

		if(array[start]==element)
			return 1;
		return 0;
	}

	if(array[middle]==element)
		return 1;

	else if(element > array[middle])
		return search(element, array, middle+1, end);
	
	else if(element < array[middle])
		return search(element, array, start, middle-1);
	
	return 0; //if it is not found in the whole array

}

int main(int argc, char *argv[]){

	FILE *file_handle = fopen("log_sarray.txt", "a");

	//used for calculating time within the function used for searching the element
	clock_t begin, end;
	double time_spent;

	int input_size;

	if(file_handle == NULL){

		printf("Error in opening of the log text files\n");
		return 0;
	}

	if(argc < 2){
		//missing number of arguments
		printf("Error : enter the value of n as an argument\n");
		return 0;
	}

	if(argv[1] != NULL){
				
		input_size = atoi(argv[1]);//now we have the input size for the program
		
	}


	//allocating dyanamic memory for the array in question
	//this step will be the same for all the three cases to be taken care of
	//memory equal to the size of the input size is assigned

	int *array = malloc(sizeof(int) * input_size);


	//Reporting error if any
	if(!array){
  		fputs("Memory allocation failed.\n", stderr);
  		exit(EXIT_FAILURE);
  	}

  	//need to generate numbers in an random order, ascending order and in the descending order

  	//generating numbers in an random order and storing them in the array

  	int search_element = input_size;
  	int i, j;


  	//generating numbers in an ascending order and storing them in the array
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = j;
  	
  	}
  	
  	begin = clock();

  	if(search(search_element, array, 0, input_size-1) ){
  		fprintf(file_handle, "%d Element Found\n", input_size);
  		exit(0);
  	}
  	

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	fprintf(file_handle, "%d %lf\n", input_size, time_spent);


}