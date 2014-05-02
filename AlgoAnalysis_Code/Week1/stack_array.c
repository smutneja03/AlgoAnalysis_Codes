
/*******************************************************

	The given program demonstrates a menu based implementation of the array implementation of stack
	The options available to the user are Push, Pop, Show and Exit
	Author : Sahil Mutneja
	Dated : 28th February 2014	
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

void push();
void pop();
void show();
void exit_call();

int array[MAX_SIZE];//size of the array is predefined
int top = -1; //empty stack

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

	if(top==MAX_SIZE - 1){

		printf("Error: Stack Overflow\n");
		return;
	}

	top = top+1;
	int element;
	printf("Enter the element you want to insert\n");
	scanf("%d", &element);
	array[top] = element;

}

void pop(){

	if(top==-1){
	
		printf("Stack is already empty\n");
	}

	else{
		
		printf("%d get popped out\n", array[top]);
		top = top - 1;
	}
}

void show(){

	int counter = 0;
	if(top==-1){
		printf("Stack is empty\n");
	}

	else{

		printf("Elements of the stack are printed below\n");
		
		while(counter-1!=top){

			printf("%d\n", array[counter]);
			counter++;
		}
	}
}

void exit_call(){

	exit(1);
}




