//Avinash Singh 2011MC04 
#include <stdio.h>
int checkprime(int n);
int main()
{
int n,i,j=0,k,flag=0;  //Variable Declaration
printf("\nEnter a number ");
scanf("%d",&n);
int arr[n];
for(i=2;i<=n;i++)
{
	if(checkprime(i)==1)   //Calling the function checkprime() to check if 'i' is prime or not
	arr[j++]=i;            //Appending the prime numbers till n to an array
}
for(i=0;i<j;i++)
{
	for(k=0;k<j;k++)
	{
		if((arr[i]+arr[k])==n)  //Checking for all pairs of prime number in the array if their sum is equal to  'n' or not
		{
		flag=1;
		printf("%d = %d + %d",n,arr[i],arr[k]);
		printf("\n");
		}
	}
}
if(flag==0)
printf("Not Possible");


return 0;
}
// Function Checkprime() Definition
checkprime(int a)
{
	int i;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}
