#include<stdio.h>
#include<malloc.h>

// Create Linked List (Polynomial)
struct Node
{
	int n_power;
	int n_coef;
	struct Node *next;
};

struct Node * createLL(int );
void printLL(struct Node *);
struct Node * addition(struct Node *,struct Node *);

int main()
{
	struct Node *first=NULL, *head=NULL, *third=NULL, *second=NULL;
	int no;
	printf("\n Enter Highest Power of 1st Polynomial : ");
	scanf("%d",&no);
	first = createLL(no);
	
	printf("\n Enter Highest Power of 2nd Polynomial : ");
	scanf("%d",&no);
	second = createLL(no);
	
	printf("\n 1st Equation \n");
	head=first;
	printLL(head);
	printf("\n 2nd Equation \n");
	head=second;
	printLL(head);
	
	third=addition(first,second);
	printf("\n Final Equation \n");
	head=third;
	printLL(head);
	
	return 0;
}
struct Node * addition(struct Node *first,struct Node *second)
{
	struct Node *fhead=NULL, *shead=NULL, *temp=NULL, *third=NULL;
	//Write your logic here
	
	
	return third;
}

void printLL(struct Node *head)
{
	while(head!=NULL) // Till End of Linked List
	{
		printf("%d X %d -> ",head->n_coef,head->n_power);
		head= head->next; // How to move to Next Node
	}
}
struct Node * createLL(int no)
{
	struct Node *first=NULL, *head=NULL, *temp=NULL;
	while(no>=0)
	{
		//Create New Node
		temp = (struct Node *)malloc(sizeof(struct Node)*1);
		temp->next=NULL;
		printf("\n Enter Power : ");
		scanf("%d",&(temp->n_power));
		printf("\n Enter Co-effcient : ");
		scanf("%d",&(temp->n_coef));
		
		//Add Node in LL
		if(first == NULL) // if LL is Empty
		{
			first = temp;
		}
		else  //if LL is not empty
		{
			head=first; // Transfering value of first into head
			while(head->next!=NULL)
			{
				head=head->next;
			}
			head->next=temp;
		}
		no--;
	}
	return first;
}
