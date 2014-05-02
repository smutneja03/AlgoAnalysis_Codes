
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node{

	int value;
	struct node *left;
	struct node *right;
};


struct node *root = NULL;

struct node *new_node(int data){


	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->value = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}

void print_inorder_iterative(struct node *root){

	struct node *stack[SIZE];
	//make an array with elements being the node with all the attributes given

	int index = 0, data;
	struct node *temp = root;

	while(index > 0 || temp !=NULL ){

		if(temp!=NULL){

			stack[index] = temp;
			index++;
			temp = temp->left;
		}	

		else{

			temp = stack[index-1];
			printf("%d\n", temp->value);
			index--;
			temp = temp->right;

		}
	}


}

struct node *add_node(struct node *root, int data){

	if(root==NULL){

		root = new_node(data);
	}

	else if(data < root->value){

		root->left = add_node(root->left, data);
	}

	else{

		root->right = add_node(root->right, data);
	}

	return root;
}



int main(){

	root = add_node(root, 7);
	root = add_node(root, 8);
	root = add_node(root, 1);
	root = add_node(root, 9);
	root = add_node(root, 0);
	root = add_node(root, 4);
	root = add_node(root, 2);
	root = add_node(root, 5);

	print_inorder_iterative(root);

}