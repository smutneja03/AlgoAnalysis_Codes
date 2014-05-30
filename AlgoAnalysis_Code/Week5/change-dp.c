#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

void get_change(int *indexing, int *array, int amount, FILE *dp){

    int coins[100], index=0, i;
    while(amount > 0){
        
        coins[index++] = array[indexing[amount]];
        //printf("%d\t", array[indexing[amount]]);
        amount = amount - array[indexing[amount]];
    }
    index--;

    merge_sort(coins, 0, index);

    int value = coins[0];
    int count=1;
    for(i=0;i<index;i++){
        if(coins[i+1]==coins[i]){
            count++;
        }
        else{
            value = coins[i+1];
            fprintf(dp, "%d\t%d\t", coins[i], count);
            count = 1;
        }

    }

    fprintf(dp, "%d\t%d\t%d\n", value, count, index+1);
}

int make_change(int *array, int number, int amount, FILE *dp){

    int count[amount+1]; //this array will keep a record of minimum number of coins required to make a change 
    int indexing[amount+1]; //will contain the index of the first coin recorded in the change
    count[0] = 0; // 0 coins are required to make a change of value 0
    indexing[0] = 0;
    int i, coin,j;

    for(i=1;i<=amount;i++){

        int min = 100;
        for(j=0;j<number;j++){

            if(array[j] <= i){

                if( 1 + count[i-array[j]] < min){
                    min = 1 + count[i-array[j]];
                    coin = j;
                }
            }
        }
        
        count[i] = min;
        indexing[i] = coin;


    }

    fprintf(dp, "%d\t", amount);

    get_change(indexing, array, amount, dp);

    return count[amount];

}

int main(int argc, char *argv[]){

	FILE *dp = fopen("log_dp.txt", "a");

    if(dp==NULL){

        printf("Error in opening of the log text files\n");
        return 0;
    }

    int coins[20];
	int i = 0, length = 0;
	int coin_value;

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
	
	while (fscanf(denom, "%d", &coin_value) > 0) {
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

    //taking the amount to be resolved from the command line 
    int amount = atoi(argv[2]);
    
    /*Dynamic Programming to solve the Coin Change Problem*/
    /*
    c(P)(minimum number of coins to make chage for amount P) = min(C(P-v(i))) + 1  it is the recursive solution
    Optimal Subtructure 
    Overlapping Subproblems
    */


    int answer = make_change(coins, length, amount, dp);    
    

    //fprintf(dp, "%d\t%d\n", amount, answer);

}

