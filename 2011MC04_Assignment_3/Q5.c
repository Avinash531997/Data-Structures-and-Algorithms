//Avinash Singh 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,m,i,j;
	printf("Enter a number\n");
	scanf("%d",&n);
	printf("\n Pattern 1 \n");
	m=n;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	
	printf("\n Pattern 2 \n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j|| i==(n-j+1))
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");
	}
		return 0;
}


