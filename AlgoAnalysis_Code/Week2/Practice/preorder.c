#include <stdio.h>
#include <stdlib.h>

struct node{

	int value;
	struct node *left;
	struct node *right;
};

//defining the properties/attributes of node

struct node *root = NULL;

//function to create a new node and set its value and left and right child
struct node *newnode(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->value = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

//after analysis adding the node in the created BINARY SEARCH TREE
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

//printing the nodes in preorder fasion
void print_preorder(struct node *root){

	if(root==NULL)
		return;
	printf("%d\n", root->value);
	print_preorder(root->left);
	print_preorder(root->right);
}



int main(){

	root = addnode(root, 1);
	root = addnode(root, 2);
	root = addnode(root, 3);
	root = addnode(root, 4);
	root = addnode(root, 5);

	//all the initial nodes have been added in the files

	print_preorder(root);

}
