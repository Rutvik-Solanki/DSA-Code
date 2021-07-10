/*
Input  : "_ _ICT _ MU _ DEPT _"
Output : "_ DEPT _ MU _ ICT _ _"
Reverse : "_ TPED _ UM _ ICI _ _"
*/

/*
STEP - 1 : Memory Allocation, get the string
STEP - 2 : Reach to Second Last Character of String
STEP - 3 : Do Memory Allocation for output String
STEP - 4 : Copy SPACE Character
STEP - 5 : SKIP Non SPACE Character
STEP - 6 : PUT '\0' at last postion of output and print it.  
*/

int main()
{
	char *mystr;
	char *output;
	int i=0,j=0,k=0,pos=0;
	//Dynamic Memory Allocation
	mystr = (char *)malloc(20*sizeof(char));
	
	printf("\n Enter Your Statement : ");
	scanf("%[^\n]s",mystr);
	
	while(*(mystr+i)!='\0')
	{
		i++;
	}
	j=i;
	--i;
	//Input  : "_ _ICT _ MU _ DEPT _" '\0'
	//-> *(mystr+i) = ____
	//Dynamic Memory Allocation
	output = (char *)malloc(20*sizeof(char));

	while(i>=0)
	{
		if(*(mystr+i)=='_')
		{
			*(output+k)=*(mystr+i);
			// j will track position which copied at last.
			j=i;
			i--;
			k++;
		}
		else
		{
			while(*(mystr+i)!='_' && i>=0) //if value is Non SPACE
			{
				i--;
			}
			for(pos=i+1;pos<j;pos++)
			{
				*(output+k)=*(mystr+pos);
				k++;
			}
		}
	}
	*(output+k)='\0';
	//*(output+5)='\0';
	printf("\n OUTPUT = %s",output);
}

