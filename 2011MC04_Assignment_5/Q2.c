//Avinash Singh 2011MC04
//Magic Square
#include<stdio.h>
#include<conio.h>
int main()
{
int n;
printf("Enter the dimension of the matrix \n");
scanf("%d",&n);
int m[n][n],s=0,i,j,sum=0;
printf("Enter the elements of the matrix \n");
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);  //Input the elements of the matrix
		}
	}

s=n*((n*n) + 1 )/2;               //Generalised sum expected in each row and column for a nxn matrix
	
for(i=0;i<n;i++)
{
	sum=0;
	for(j=0;j<n;j++)
	{
		sum+=m[i][j];  //Sum of elements in a row	
	}
	if(sum!=s)         //if sum of the elements in the row is not equal to s. It is not a magic square.
	{
		printf("Not a magic square");
		return 0;
	}
}

for(i=0;i<n;i++)
{
	sum=0;
	for(j=0;j<n;j++)
	{
		sum+=m[j][i];  //Sum of elements in a column	
	}
	
	if(sum!=s)		  //if sum of the elements in the row is not equal to s. It is not a magic square.
	{
		printf("Not a magic square");
		return 0;
	}
}
printf("Magic Square \n");
return 0;
}




