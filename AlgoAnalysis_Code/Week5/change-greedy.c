#include <stdio.h>
#include <stdlib.h>

void merge(float *array, int start, int mid, int end){

  float temp[end];
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

void merge_sort(float *array, int start, int end){

  float mid;

  if(start<end){

    mid = (start+end)/2;
    merge_sort(array, start, mid);
    merge_sort(array, mid+1, end);

    merge(array, start, mid, end);
  }

}

int main(int argc, char *argv[]){

	float coins[20];
	int i = 0, length = 0;
	float coin_value;
	float bag[100]; //will store the coins used to get the given value

	if(argc < 2){
		printf("Enter the text file contaning the value of the denominations\n");
		exit(1);
	}

	if(argc < 3){
		printf("Enter the value you want to get the change of\n");
		exit(1);
	}

	/*getting the contents of the denomination file into our array which now contains the float values*/
	FILE *denom = fopen(argv[1], "r");
	if(denom==NULL){
		printf("Error:File pointer is null\n");
		exit(1);
	}
	
	while (fscanf(denom, "%f", &coin_value) > 0) {
        coins[i++] =  coin_value;
        length++;
    }

    fclose(denom);

  	/* Greedy Algorithm */
  	/* Algorithm for the code
	1. Create an empty bag
	2. while (x > 0) {
	Find the largest coin c at most x;
	Put c in the bag;
	Set x = x –c ;
	}
	3. Return coins in the bag
	*/

    /*sending the arrray for sorting for further processing*/
    merge_sort(coins, 0, length-1);

    float amount = atof(argv[2]);
    int length_bag;
    float largest_value;

    while(amount > 0.0) {

    	largest_value = 0;
    	for (i = length-1; i >=0; i--){
    		
    		if(coins[i] <= amount && coins[i] > largest_value){
    			largest_value = coins[i];
    		}
    	}

    	if(largest_value==0){
    		printf("Greedy Solution Not Found\n");
    		exit(1);
    	}

    	//here we have got the maximum largest coin
    	bag[length_bag++] = largest_value;
    	amount = amount - largest_value;
    }

    //here we have gone throught he loop to find the greedy solution

    for(i=0;i<length_bag;i++)
    	printf("%.2f\n", bag[i]);

}

