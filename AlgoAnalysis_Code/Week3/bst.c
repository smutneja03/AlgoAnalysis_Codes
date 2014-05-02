
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{

	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node *add_node(struct node *root, int data){

	if(root==NULL)
		root = new_node(data);
	else if(data > root->data)
		root->right = add_node(root->right, data);
	else
		root->left = add_node(root->left, data);

	return root;
}

int search(struct node *root, int element){

	if(root==NULL)
		return 0;
	if(element==root->data)
		return 1;
	else if(element > root->data)
		return search(root->right, element);
	else
		return search(root->left, element);

}

int main(int argc, char *argv[]){

	FILE *log_random = fopen("log_bst_random.txt", "a");
	FILE *log_asc = fopen("log_bst_asc.txt", "a");
	FILE *log_desc = fopen("log_bst_desc.txt", "a");

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

	//inserting elements into the binary  search tree

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
  	int j, i;

  	/*First Part starts from here for the random order combination*/
  	
  	for (j = 0; j < input_size; j++){
  		//will store in the BST numbers in a random order equal to the input size
  		root = add_node(root, rand() % input_size);
  	
  	}

  	//beginning with the internal time counter
  	begin = clock();

  	search(root, input_size);

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


  	fprintf(log_random, "%d %lf\n", input_size, time_spent);
  	
  	/*Second Part starts from here for the random order combination*/
  	
   	root = NULL;


  	//generating numbers in an ascending order and storing them in the array
  	for (j = 0; j < input_size; j++){
  		//will store in the array numbers in a random order equal to the input size
  		root = add_node(root, j);
  	
  	}
  	

  	begin = clock();

  	search(root, input_size);

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  	fprintf(log_asc, "%d %lf\n", input_size, time_spent);

  	//Third Part starts from here for the random order combination
  	
  	root = NULL;
 
  	//generating numbers in an descending order and storing them in the array
  	for (j = input_size-1; j >= 0; j--){
  		//will store in the array numbers in a random order equal to the input size
  		root = add_node(root, j);
  	
  	}
  	
  	begin = clock();

  	search(root, -1);
  	
  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  	fprintf(log_desc, "%d %lf\n", input_size, time_spent);



}


