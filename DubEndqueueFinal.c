#include<stdio.h>
#include<malloc.h>

//Creating Structure
struct Student
{
	int rollno;
	struct Student *connection;	
}; 
struct Student *start=NULL;
struct Student *temp=NULL,*head=NULL;

void enqueue(int );
void printQueue();
void dequeue();

int main()
{
	dequeue();
	enqueue(1);
	enqueue(5);
	enqueue(4);
	enqueue(3);
	printQueue();
	// 1-> 5-> 4 -> 3
	dequeue();
	// 5-> 4 -> 3
	printQueue();
	
	return 0;
}
void enqueue(int value)
{
		head=NULL;
		//Create New Node
		//Will aquire memory from compiler
		temp = (struct Student *) malloc(sizeof(struct Student));
		temp->rollno=value;
		temp->connection=NULL;
		
		if(start==NULL) //if start is Empty or pointing to NULL
		{
			start=temp;
		}
		//Add new Node at the End of Linked List
		else 
		{
			head=start;
			while(head->connection!=NULL)
			{
				head= head->connection;
			}
			head->connection=temp;
		}
}

void dequeue()
{
	if(start==NULL)
	{
		printf("Queue is Empty");
	}
	else
	{
		temp=start;
		start = start->connection;
		free(temp);
	}
}

void printQueue()
{
	head = start;
	printf("\n");
	while(head!=NULL)
	{
		printf("%d -> ",head->rollno);
		head = head->connection;
	}
}
