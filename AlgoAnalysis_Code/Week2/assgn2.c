
/*******************************************************

	The given program demonstrates a Binary Search Tree with a number of traversals namely Preorder, Inorder and Postorder
	The options available to the user are Push, Pop, Show and Exit
	Author : Sahil Mutneja
	Dated : 28th February 2014	
*******************************************************/

#include <stdio.h>
#include <stdlib.h>


//defining the structure of the node for the tree
struct node{

	int value;
	struct node *left;
	struct node *right;
};

void postorder(struct node *);
void preorder(struct node *);
void inorder(struct node *, FILE *);

//initialising the root node to be as NULL
struct node *root = NULL;


//function to create a new node for insertion into BST
struct node *newnode(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->value = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

//function to add a new node into Binary Search Tree with its property in place
struct node *addnode(struct node *root, int data){

	if(root==NULL){
		//this is the first node to be entered
		root = newnode(data);

	}

	else if(data < root->value){

		root->left = addnode(root->left, data);
		
	}

	else{

		root->right = addnode(root->right, data);
	}

	return root;

}


//printing the nodes in inorder fashion with first the left child then the root and then the right child
void inorder(struct node *root, FILE *check_inorder){
	if(root==NULL)
		return;
	inorder(root->left, check_inorder);
	printf("%d\t", root->value);
	//storing the values in a text file
	fprintf(check_inorder, "%d\n", root->value);
	inorder(root->right, check_inorder);
}

//printing the nodes in postorder fashion with first the left child then the right child and then the root
void postorder(struct node *root){

	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->value);
}

//printing the nodes in preorder fashion with first the root then left and then right child
void preorder(struct node *root){

	if(root==NULL)
		return;
	printf("%d\t", root->value);
	preorder(root->left);
	preorder(root->right);
}

//searching a key in the Binary Search Tree for its existence
void search(struct node *root, int data){

	if(root==NULL){

		printf("Key %d is not found\n", data);
		return;
	}

	if(root->value == data){

		printf("Key %d is present in the tree\n", data);
	}

	else if(data < root->value){

		search(root->left, data);
	}

	else{

		search(root->right, data);
	}
}



int main(int argc, char *argv[]){

	//putting the values into the inorder.txt files for further processing whethere its sorted or not
	FILE *check_inorder = fopen("inorder.txt", "a");

	if(check_inorder==NULL){

		printf("Error in opening the check inorder file .txt\n");
		return 0;
	}

	//beginning the main part of the solution

	if(argc < 2){
		//missing number of arguments
		printf("Error : enter the text file followed by the key to search\n");
		return 0;
	}

	else{

		//argv[1] is the file that needs to be opened

		FILE *file_handle = fopen(argv[1], "r"); //will return 0 or null if failed to open

		int i;

		if(file_handle == 0 || file_handle==NULL){

			printf("Could not open file\n");
		}

		else{

			fscanf(file_handle, "%d", &i);
			
			while(!feof(file_handle)){

				root = addnode(root, i);
				fscanf(file_handle, "%d", &i);
			}

			printf("\nInorder Traversal\n");
			inorder(root, check_inorder); //for the file to be kept a track of 
			printf("\n");
			printf("Postorder Traversal\n");
			postorder(root);
			printf("\n");
			printf("Preorder Traversal\n");
			preorder(root);
			printf("\n");


			//checking and searching for the existence of the entered number

			if(argv[2] != NULL){
				
				int val = atoi(argv[2]);
				search(root, val);
			
			}

			return 1;
		}

	}

}

