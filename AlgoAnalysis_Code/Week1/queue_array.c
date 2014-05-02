
/*******************************************************

	The given program demonstrates a menu based implementation of the array implementation of queue
	The options available to the user are Push, Pop, Show and Exit
	Author : Sahil Mutneja
	Dated : 28th February 2014	
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

void enqueue();
void dequeue();
void show();
void exit_call();

int array[MAX_SIZE]; //size of the array is predefined
int front = -1; //empty stack
int rear = -1;


int main(){

	int choice;

	//endless loop to input the value from the user and perform the requisite operation

	while(1){
	
		printf("Enter the choice of operation\n");
		printf("1.Enqueue\n2.Dequeue\n3.Show\n4.Exit\n" );

		scanf("%d", &choice);

		if(choice==1){
			enqueue();
		}

		else if(choice==2){

			dequeue();
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


void enqueue(){

	if(rear==MAX_SIZE - 1){

		printf("Error: Stack Overflow\n");
		return;
	}

	else if(front==-1 && rear==-1){

		front = 0;
		rear = 0;
	}

	else{

		rear = rear + 1;
	}

	int element;
	printf("Enter the element you want to insert\n");
	scanf("%d", &element);

	array[rear] = element;

}

void dequeue(){

	if(front==-1 && rear==-1){
	
		printf("Stack is already empty\n");
	}

	else if(front==rear){
	//queue is empty, all the elements have been dequeued out
		printf("%d get dequeued out\n", array[front]);
		printf("We just dequeued the last value\n");		
		front = -1;
		rear = -1;
	}
	else{
		
		printf("%d get dequeued out\n", array[front]);
		front = front + 1;
	}
}

void show(){

	int start = front;
	int end = rear;

	if(front==-1 && rear==-1){
		printf("Stack is empty\n");
	}

	else{

		printf("Elements of the stack are printed below\n");
					
		while(start!=end){	
			printf("%d\n", array[start]);
			start++;

		}

		printf("%d\n", array[end]);

	}

}



void exit_call(){

	exit(1);
}


