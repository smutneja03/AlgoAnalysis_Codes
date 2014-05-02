
/*******************************************************

	The given program demonstrates a menu based implementation of the linked list implementation of queue
	The options available to the user are Push, Pop, Show and Exit
	Author : Sahil Mutneja
	Dated : 28th February 2014	
*******************************************************/


#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void show();
void exit_call();

struct node
{
	int data;
	struct node *next;
};

struct node *front = NULL; //initially stack is empty
struct node *rear = NULL;


int main(){

	int choice;

	//endless loop to input the value from the user and perform the requisite operation

	while(1){
	
		printf("\nEnter the choice of operation\n");
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

	int element;
	printf("Enter the element you want to insert\n");
	scanf("%d", &element);

	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	//adding elements to the head of the linked list
	//top will be the latest element added
	temp->data = element;
	temp->next = NULL;
	if(front==NULL && rear==NULL){
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

void dequeue(){

    struct node *temp = front;
	
	if(temp==NULL){
		printf("Queue is already empty\n");
		return;
	}
	else if(front == rear){

		printf("%d get dequeued out\n", front->data );
		front = rear = NULL; //last element will be dequeued out
	}

	else{

		printf("%d get dequeued out\n", front->data ); //dequeuing of the elements are being done from the front
		front = front->next;
	}
}

void show(){

	struct node *head = front;

	if(head==NULL){
		printf("Enter elements first\nQueue is empty\n");
		return;
	}

	printf("The elements are printed below\n");
	while(head!=rear){

		printf("%d\n", head->data);
		head = head->next;
	}

	printf("%d\n", head->data);

}


void exit_call(){

	exit(1);
}




