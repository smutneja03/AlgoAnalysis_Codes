
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	FILE *log_random = fopen("log_array_random.txt", "a");
	FILE *log_asc = fopen("log_array_asc.txt", "a");
	FILE *log_desc = fopen("log_array_desc.txt", "a");

	//used for calculating time within the function used for searching the element
	clock_t begin, end;
	double time_spent;

	int input_size;

	if(log_random==NULL || log_asc==NULL || log_desc==NULL){

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
  	int j;
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = rand() % input_size;
  	
  	}
  	int search_element = input_size;
  	int i;

  	//beginning with the internal time counter
  	begin = clock();

  	for (i = 0; i < input_size; i++){

  		if(search_element == array[i]){
  			fprintf(log_random, "%d Element Found\n", input_size);
  			exit(0);
  		}
  	}

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


  	fprintf(log_random, "%d %lf\n", input_size, time_spent);


  	//generating numbers in an ascending order and storing them in the array
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = j;
  	
  	}
  	
  	search_element = input_size;

  	begin = clock();

  	for (i = 0; i < input_size; i++){

  		if(search_element == array[i]){
  			fprintf(log_asc, "%d Element Found\n", input_size);
  			exit(0);
  		}
  	}

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	fprintf(log_asc, "%d %lf\n", input_size, time_spent);


  	//generating numbers in an descending order and storing them in the array
  	for (j = input_size-1; j >= 0; j--){
  		//will store in the array numbers in a random order equal to the input size
  		array[j] = j;
  	
  	}
  	
  	search_element = input_size;

  	begin = clock();
  	
  	for (i = 0; i < input_size; i++){

  		if(search_element == array[i]){
  			fprintf(log_desc, "%d Element Found\n", input_size);
  			exit(0);
  		}
  	}
  	
  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  	fprintf(log_desc, "%d %lf\n", input_size, time_spent);

}