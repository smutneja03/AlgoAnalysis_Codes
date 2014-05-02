
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void count_sort(int *array, int start, int end){

    // The output character array that will have sorted str
    int output[end];
 
    // Create a count array to store count of inidividul characters and
    // initialize count array as 0
    int count[end], i;
    
    for (i = 0; i <= end; i++){
       count[i] = 0;
     } 

    // Store count of each character
    for(i = 0; i<=end; i++)
      count[array[i]]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this character in output array
    for (i = 1; i <= end; i++)
      count[i] += count[i-1];
 
    // Build the output character array
    for (i = end; i>=0; i--){
      output[count[array[i]]-1] = array[i];
      count[array[i]]--;
    }
 
    // Copy the output array to str, so that str now
    // contains sorted characters
    for (i = 0; i<=end; i++)
        array[i] = output[i];


}

  

int main(int argc, char *argv[]){

	FILE *log_average = fopen("log_count_average.txt", "a");
	FILE *log_best = fopen("log_count_best.txt", "a");
	FILE *log_worst = fopen("log_count_worst.txt", "a");

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
  	int j, temp, i;
    int list[input_size];

    for (j = 0; j < input_size; j++){
      
      list[j] = j;
    }
  	
    for (i = 0; i < input_size; i++){
  		//will store in the array numbers in a random order equal to the input size
    	j = i + rand() % (input_size - i);
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;

      array[i] = list[i];

  	}


  	//beginning with the internal time counter
  	begin = clock();

  	count_sort(array, 0, input_size-1);//calling the count sort function for sorting the array
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

    count_sort(array, 0, input_size-1);

  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	fprintf(log_best, "%d %lf\n", input_size, time_spent);


    //The best case input is an array that is already sorted. In this case count sort has a linear running time (i.e., Θ(n)). 
  	//generating numbers in an descending order and storing them in the array
  	i = 0;
    
    for (j = input_size-1; j >= 0; j--){
  		//will store in the array numbers in a random order equal to the input size
  		array[i++] = j;
  	
  	}
  	

  	begin = clock();
  	
    count_sort(array, 0, input_size-1);
  	
  	//ending with the internal time counter
  	end = clock();


  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  	fprintf(log_worst, "%d %lf\n", input_size, time_spent);

    //The simplest worst case input is an array sorted in reverse order.
    //This gives count sort a quadratic running time (i.e., O(n2)).
}


