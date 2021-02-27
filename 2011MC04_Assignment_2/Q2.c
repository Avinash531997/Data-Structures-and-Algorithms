//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	printf("Enter length of array  ");  //take n as input
	scanf("%d",&n);
	int i,j,a[n],s=0,x=0;
	printf("Enter elements of the array"); 
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);  //take the array as input
	
	for(i=0;i<n;i++)    //Exploring the array with nested loop. This will take O(n^2) time.
	{
		for(j=i;j<n;j++)
		{
			s+=a[j];
			if(s%2==0)    //if sum is even then increment x
			x+=1;	
		}
		s=0;
	}
	printf("Number of Subarrays with even sum = %d \n",x);
return 0;
}

