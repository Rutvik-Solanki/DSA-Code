/*
1. In-Built Function (Provided by Language) -> X
2. User Defined Function

USER Defined FUNCTION
1. Argument, Return Value
2. No Argument, No return value
3. Argument, No return Value
4. No Argument, return value
*/

// Declaration

int addition(int, int);
void printAuthorInfo(); 
void printval(int);
float getPI();

int main()
{
	printAuthorInfo();
	//printf(" SUM = %d", ); // Function Call 20, 35 -> Actual Arguments
	printval(addition(20,35)); // Function calling another function (parameter)
	printf("\n Value of PI = %.2f",getPI());
	return 0;
}

// 1. Argument, Return Value
//Function Body - Definition
// i, j are called parameters (Formal)
int addition(int i, int j)
{
	return (i+j);
}

// 2. No Argument, No return value
void printAuthorInfo()
{
	printf("\n================================");
	printf("\n Program done By Kapil Shukla");
	printf("\n Date -  20th July, 2020");
	printf("\n ICT Sem - 3 Batch - B");
	printf("\n================================\n");
}

// 3. Argument, No return Value
void printval(int val)
{
	printf("\n value is  : %d", val);
}

//4. No Argument, return value
float getPI()
{
	return 3.14;
}
