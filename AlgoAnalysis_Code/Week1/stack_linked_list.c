
/*******************************************************

	The given program demonstrates a menu based implementation of the linked list implementation of stack
	The options available to the user are Push, Pop, Show and Exit
	Author : Sahil Mutneja
	Dated : 28th February 2014	
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void show();
void exit_call();

struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL; //initially stack is empty



int main(){

	int choice;

	//endless loop to input the value from the user and perform the requisite operation

	while(1){
	
		printf("Enter the choice of operation\n");
		printf("1.Push\n2.Pop\n3.Show\n4.Exit\n" );

		scanf("%d", &choice);

		if(choice==1){
			push();
		}

		else if(choice==2){

			pop();
		}

		else if(choice==3){

			show();
		}

		else if(choice==4){

			exit_call();
		}

		else{

			printf("Please enter a valid entry\n");
		}
	}

}

void push(){

	int element;
	printf("Enter the element you want to insert\n");
	scanf("%d", &element);

	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	//adding elements to the head of the linked list
	//top will be the latest element added
	temp->data = element;
	temp->next = top;
	top = temp;
}

void pop(){

	struct node *temp;
	if(top ==NULL){
		printf("Stack is empty\nEnter elements first\n");
		return;
	}
	temp = top;
	//extracting out the 
	printf("%d got popped out\n", top->data);
	top = top->next;
	free(temp);
	
}

//recursive function to print the reverse of the linked list
void printReverse(struct node *head){

	if(head==NULL)
		return;

	printReverse(head->next);

	printf("%d\n", head->data);

}

void show(){

	struct node *head = top;

	if(head==NULL){

		printf("Stack is empty\n");
		return;
	}

	printReverse(head);

}


void exit_call(){

	exit(1);
}




