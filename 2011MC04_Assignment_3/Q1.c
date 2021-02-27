//Avinash Singh 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	printf("Enter array length\n");
	scanf("%d",&n);
	printf("Enter array elements");
	int a[n],i,s,j,k,flag=0;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter value of sum \n");
	scanf("%d",&s);
	for(i=0;i<n;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(a[i]+a[j]+a[k]==s)        //checking if sum of triplets = s or not?
				{
				printf("%d,%d,%d \n",a[i],a[j],a[k]); //printing the triplet 
				flag=1;
				}
			}
		}
	}
	if(flag==0)
	printf("False");
	return 0;
}
