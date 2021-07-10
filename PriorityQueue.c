#include<stdio.h>
#include<malloc.h>

//Creating Process Structure
struct Process
{
	int processNo;
	int priority;
	struct Process *next;	
}; 

struct Process *start=NULL, *head=NULL;

//Declaration of Functions
void displayMenu();
void Enqueue();

int main()
{
	int op,val;
	do
	{
		displayMenu();
		printf("\n Select Operation : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
					Enqueue();
				break;
			case 2:
					
				break;
			case 3:
					
				break;
		}		
	}while(op!=4);
	
	return 0;
}

void displayMenu()
{
	printf("\n=======================");
	printf("\n  Priority Queue Menu");
	printf("\n=======================");
	printf("\n  1 -  Enqueue");
	printf("\n  2 -  Dequeue ");
	printf("\n  3 -  Print Queue ");
	printf("\n  4 -  Exit ");
	printf("\n=======================");
}
void Enqueue()
{
	struct Process *temp=NULL;
	
	//New Process is Created
	temp=(struct Process *)malloc(sizeof(struct Process)*1);
	printf("\n Enter Process No :");
	scanf("%d",&(temp->processNo));
	printf("\n Enter Priority for Process :");
	scanf("%d",&(temp->priority));
	temp->next=NULL;
	
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		head=start;
		while()
		{
			head=head->next;
		}
		
	}
	
}



