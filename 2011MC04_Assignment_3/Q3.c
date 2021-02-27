//Avinash Singh 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	printf("Enter array length\n");
	scanf("%d",&n);
	printf("Enter array elements");
	int a[n],i,j,min_index,min,max,max_index;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	min=a[0];
	
	
	for(i=0;i<n;i++)
	{
		if(a[i]<min)   
		{
			min_index=i; //fiding the index of minimum element
			min=a[i];
		}
	}
	
	max=a[min_index];
	if( min_index!=n-1)   //if min_index is not equal to last index of array we proceed else we stop
	{
		for(j=min_index+1;j<n;j++)
		{
			if(a[j]>max)
			{
			max=a[j];
			max_index=j; //fiding the index of maximum element
			}
		}
		printf("%d \n",(max-min)); //Calcuating and printing the Profit 
	}
	else
	{
		printf("0");
	}
	return 0;
}
