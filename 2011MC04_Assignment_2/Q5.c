//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
  	int n,i,j,k,m,t,b,a;
	printf("Enter a  number ");  //take n as input
	scanf("%d",&n);
	int arr[n];
	for(i=1;i<=n;i++)
	arr[i]=0;
	printf("Enter the number of queries you want to give ");
	scanf("%d",&t);
	int q[t][3];
	printf("Enter the query matrix"); //enterig the query matrix
	for(i=1;i<=t;i++)
	{
		for(j=1;j<=3;j++)
		scanf("%d",&q[i][j]);
	}
	printf("So we have taken the inputs, Let's start processing \n");
	for(i=1;i<=t;i++)
	{
	a=q[i][1];
	b=q[i][2];
	k=q[i][3];
		for(m=a;m<=b;m++)   //modifying the values
		arr[m]+=k;
	}
	int largest=arr[1];
	for(i=1;i<=n;i++)
	{
		if(arr[i]>largest) //finding the larget number
		largest=arr[i];
	}
printf("Largest number =%d",largest);	
return 0;
}


