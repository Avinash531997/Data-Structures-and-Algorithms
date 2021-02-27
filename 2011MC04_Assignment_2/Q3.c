//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j,k,m;
	printf("Enter a  number ");  //take n as input
	scanf("%d",&n);
	for(i=1;i<=n;i++) //Loop for each line of the pattern
	{
		for(j=n;j>i;j--) //To print the empty spaces in each line
		{
		printf(" ");
		}
		for(k=1;k<=i;k++) //to print * till the middle of the pattern
		printf("*");
		for(m=1;m<=i-1;m++) //to print * from middle to end of the pattern
		printf("*");
		printf("\n");
	}
	return 0;
}

