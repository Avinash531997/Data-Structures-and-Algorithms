//Avinash Singh 2011MC04 
#include <stdio.h>
int main()
{
	int a=0,b=1,i=2,n,c;  //Variable Declaration
	printf("Enter the value of  n ");
	scanf("%d",&n);
	printf("%d  %d  ",a,b);
	while(i<n)
	{
		c=a+b;
		a=b;
		b=c;
		printf(" %d ",c); //Printing the Fibonacci Series
		i++;
	}
	
return 0;
}


