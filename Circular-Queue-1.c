#include<stdio.h>
#include<malloc.h>

//Global Declaration
struct Node
{
	int value;
	struct Node *next;
}*front=NULL,*rear=NULL;

int QSize;
int f=-1,r=-1;

//Function Declaration
void QueueOperations();
void enqueue(int);
void dequeue();
void printQueue();

int main()
{
	int choice=0,value;
	printf("\n Enter Your Queue Size : ");
	scanf("%d",&QSize);
	do
	{
		QueueOperations();
		printf("\n Enter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\n Enter Value for Queue : ");
					scanf("%d",&value);
					enqueue(value);
				break;
			case 2:
					dequeue();
				break;
			case 3:
					printQueue();
				break;
		}
	}while(choice!=4);
	return 0;
}
void QueueOperations()
{
	printf("\n =========================");
	printf("\n     Queue Opeartions");
	printf("\n =========================");
	printf("\n   1 - Enqueue");
	printf("\n   2 - Dequeue");
	printf("\n   3 - Print");
	printf("\n   4 - Exit");
	printf("\n =========================");	
}
void enqueue(int n)
{
	struct Node *temp=NULL;
	if(r-f==QSize)
	{
		printf("\n Queue is Full");
	}
	else
	{
		temp=(struct Node *)malloc(sizeof(struct Node)*1);
		//temp->next=front;  //circular queue
		temp->value=n;
		
		if(front==NULL && rear==NULL) //Empty
		{
			front=temp;
			rear=temp;
			//circular queue
			rear->next=front;
		}
		else
		{
			rear->next=temp;
			rear=temp;
			//circular queue
			rear->next=front;
		}
		r++;
	}
}
void dequeue()
{
	struct Node *temp=NULL;
	if(r==-1) //Empty
	{
		printf("\n Queue is Empty");
	}
	else if(r==0) // Single Node
	{
		temp=front;
		rear=NULL;
		front=NULL;
		printf("\n %d is dequeued",temp->value);
		free(temp);
		r--;
	}
	else // Multiple Node
	{
		temp=front;
		//circular queue
		rear->next=front->next;
		front=front->next;
		printf("\n %d is dequeued",temp->value);
		free(temp);
		r--;
	}
}
void printQueue()
{
	struct Node *head=NULL;
	if(r!=-1)  // Circular Queue
	{
		head=front;
		do
		{
			printf("%d -> ",head->value);
			head=head->next;
		}while(head!=front); // Circular queue
	}
	else
	{
		printf("\n Queue is Empty");
	}
}
