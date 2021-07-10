#include<stdio.h>
#include<malloc.h>
#include<string.h>

//for LL Opearation 
struct MyStr
{
	char ch;
	struct mystr *next;
};

//Global Declaration  Section
struct MyStr *infix=NULL, *postfix=NULL, *stack=NULL;

void strToLL(char *);
void printLL(struct MyStr *);
void printLLR(struct MyStr *);
void infixToPostfix();
int getPriority(char );
int operatorORoperand(char);
void addToPostfix(char);
void setStack();
void push(char ch);
char pop();

int main()
{
	char *p;
	struct MyStr *head=NULL;
	p=(char *)malloc(sizeof(char)*50);
	printf("\n Enter Infix String :");
	scanf("%s",p);
	
	//Creating LL-Infix from String
	strToLL(p);
	
	
	//printing Infix
	head=infix;
	printf("\n Infix = ");
	printLL(head);
	
	//add '(' into Stack
	setStack();
	
	//Start Process of INFIX -> POSTFIX
	infixToPostfix();
	
	//print POSTFIX
	head=postfix;
	printf("\n Postfix = ");
	printLL(head);
	
	return 0;
}

void setStack()
{
	stack = (struct MyStr *)malloc(sizeof(struct MyStr)*1);
	stack->ch='(';
	stack->next=NULL;
}

int getPriority(char ch)
{
	switch(ch)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}
int operatorORoperand(char ch)
{
	//operator
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
	{
		return 0;
	}
	else
	{
		//operand
		return 1;
	}
}
void strToLL(char *p)
{
	int i=0;
	struct MyStr *head=NULL, *temp=NULL;
	while(*(p+i) !='\0')
	{
		//New Node with Character
		temp = (struct MyStr *)malloc(sizeof(struct MyStr)*1);
		temp->ch=*(p+i);
		temp->next=NULL;
		
		if(infix==NULL)
		{
			infix=temp;
		}
		else
		{
			head=infix;
			while(head->next!=NULL)
			{
				head=head->next;
			}
			head->next=temp;
		}
		i++;
	}
}

void printLL(struct MyStr *head)
{
	while(head!=NULL)
	{
		printf("%c",head->ch);
		head=head->next;
	}
}

void printLLR(struct MyStr *head)
{
	if(head==NULL)
	{
		return;
	}
	printLLR(head->next);
	printf("%c",head->ch);
}

void infixToPostfix()
{
	struct MyStr *inhead=NULL,*pohead=NULL,*temp=NULL,*tos=NULL;
	
	inhead=infix;
	while(inhead!=NULL)
	{
		
		//if operand
		if(operatorORoperand(inhead->ch)==1)
		{
			addToPostfix(inhead->ch);
		}
		//if operator
		else
		{
			//comparing priority of Operator
			if(getPriority(stack->ch) < getPriority(inhead->ch))
			{
				push(inhead->ch);
			}
			//== or >
			else
			{
				while(getPriority(stack->ch) >= getPriority(inhead->ch))
				{
					//pop character from Stack and Added into Postfix
					addToPostfix(pop());
				}
				//'-'
				push(inhead->ch);
			}
		}
		
		//Process of One Character is DONE.
		printf("\n");
		printf("%c | ",inhead->ch);
		tos=stack;
		printLLR(tos);
		printf(" | ");
		pohead=postfix;
		printLL(pohead);
		printf("\n");
		
		inhead=inhead->next;
	}
	
	//When Infix Expression is Completed - Empty Stack
	while(stack->ch != '(')
	{
		addToPostfix(pop());
	}
	
	
}

void addToPostfix(char c)
{
	struct MyStr *temp=NULL,*head=NULL;
	temp = (struct MyStr *)malloc(sizeof(struct MyStr)*1);
	temp->ch=c;
	temp->next=NULL;
		
	if(postfix==NULL)
	{
		postfix=temp;
	}
	else
	{
		head=postfix;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=temp;
	}
}

void push(char ch)
{
	struct MyStr *temp=NULL;
	temp = (struct MyStr *)malloc(sizeof(struct MyStr)*1);
	temp->ch=ch;
	temp->next=NULL;
	
	//Add Node at First Place in Stack
	temp->next=stack;
	stack=temp;
}

char pop()
{
	struct MyStr *temp=NULL;
	char ch;
	ch = stack->ch;
	
	temp=stack;
	stack=stack->next;
	free(temp);
	
	return(ch);
}
