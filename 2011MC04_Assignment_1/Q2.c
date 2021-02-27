//Avinash Singh 2011MC04 

#include <stdio.h>
int main()
{
int n,i,j;  //Variable Declaration
printf("\nEnter a number ");
scanf("%d",&n);
for(i=1;i<=n;i++) //For loop that executes n times. 
{
	for(j=1;j<=i;j++)  
	printf("%d",j);    //Printing the pattern
	printf("\n");
}
return 0;
}

