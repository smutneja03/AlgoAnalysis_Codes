
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{

	int data;
	struct node *left;
	struct node *right;
	int height; 
};

struct node *root = NULL;

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1; //new node is at leaf level

	return temp;
}

// A utility function to get maximum of two integers
int max(int a, int b){

	if(a>b)
		return a;
	else
		return b;
}

// A utility function to get height of the tree
int height(struct node *temp){

	if(temp==NULL)
		return 0;
	
	return temp->height;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y){

    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x){

    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

int get_balance(struct node *node){

	if(node==NULL)
		return 0;

	return height(node->left) - height(node->right);
}

struct node *add_node(struct node *node, int data){

	if(node==NULL)
		return new_node(data);
	
	if(data > node->data)
		node->right = add_node(node->right, data);
	
	else if(data < node->data)
		node->left = add_node(node->left, data);
	else
		return node;

	//now operations needs to be performed to check whether the height balanced property is satisfied or not

	node->height = max(height(node->left), height(node->right)) + 1;

	int balance = get_balance(node);

	// Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
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

	FILE *log_random = fopen("log_balanced_bst_random.txt", "a");
	FILE *log_asc = fopen("log_balanced_bst_asc.txt", "a");
	FILE *log_desc = fopen("log_balanced_bst_desc.txt", "a");

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


  	//need to generate numbers in an random order, ascending order and in the descending order

  	//generating numbers in an random order and storing them in the array
  	int j;
  	for (j = 0; j < input_size; j++){
  		//will store in the BST numbers in a random order equal to the input size
  		root = add_node(root, rand() % input_size);
  	
  	}

  	int search_element = input_size;
  	int i;

  	//beginning with the internal time counter
  	begin = clock();

  	search(root, search_element);

  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


  	fprintf(log_random, "%d %lf\n", input_size, time_spent);

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

  	root = NULL;

  	//generating numbers in an descending order and storing them in the array
  	for (j = input_size-1; j >= 0; j--){
  		//will store in the array numbers in a random order equal to the input size
  		root = add_node(root, -1);
  	
  	}
  	
  	search_element = input_size;

  	begin = clock();

  	search(root, search_element);
  	
  	//beginning with the internal time counter
  	end = clock();

  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  	fprintf(log_desc, "%d %lf\n", input_size, time_spent);


}


