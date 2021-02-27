//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
int arr[7][7],i,j,a,b,c,d,e,f,g,sum,largest=0;
//Input a 6x6 array
for(i=1;i<=6;i++)
{
	for(j=1;j<=6;j++)
	{
		scanf("%d",&arr[i][j]);
	}
}
// considering each submatrix of dimension 3x3 for considering hourglass
for(i=1;i<=4;i++)
{
	for(j=1;j<=4;j++)
	{
		
	//taking each part of hourglass and initializing it to vaiables 
	a=arr[i][j];
	b=arr[i][j+1];
	c=arr[i][j+2];
	d=arr[i+1][j+1];
	e=arr[i+2][j];
	f=arr[i+2][j+1];
	g=arr[i+2][j+2];
	sum=a+b+c+d+e+f+g;  //finding the sum of elements of an hourglass
	if(largest<sum)   //finding the largest sum
	largest=sum;  
	sum=0;
	}
}
printf("Highest sum is %d",largest);
return 0;
}



