//Avinash Singh 2011MC04
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n;
	printf("Enter array length\n");
	scanf("%d",&n);
	printf("Enter array elements");
	int a[n],i,j,k,total;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	total=pow(2,n);   //Calculating Total possible subsets and storing the value in Total
	for(i=1;i<=total;i++) //Here we are actually trying to explore all possible binary combinations that can be formed using n bits.
	{
		printf("[");
		for(j=0;j<n;j++) 
		{
			if(i&(1<<j))   //checking if jth bit of the element i is set or not, is it is set we print the element at that position in my array
			
			{
				printf("%d ",a[j]);
			}
		}
		printf("]");
		//printf("\n");
	}
	return 0;
}
