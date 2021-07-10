#include<stdio.h>

//Function Declaration
void printVal(int );
int sum(int);

int main() // -> Teacher
{
	//printVal(1);
	printf("\n SUM = %d",sum_r(5)); // 5+4+3+2+1=15 1+2+3+4+5=15
	return 0;
}

int sum(int n)
{
	static int s=0;
	if(n==0)
	{
		return s;
	}
	s =s + n; // 5+4+3+2+1=15
	sum(n-1);
	//s =s + n; // 1+2+3+4+5=15
}
int sum_r(int n)
{
	if(n==0)
	{
		return 0;
	}
	return n+sum_r(n-1);
}

//5+4+3+2+1+0=15

//3 2 1 1 2 3 -> Output
void printVal(int n) 
{
	if(n==5)
	{
		return;
	}
	printf("\n%d - Name",n); // Name
	printVal(n+1);
	printf("\n%d - Surname",n); // Surname
	
}




