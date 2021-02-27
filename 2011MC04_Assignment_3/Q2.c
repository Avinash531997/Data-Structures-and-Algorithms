//Avinash Singh 2011MC04
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,t,r,s=0;
	printf("Enter a positive  integer \n");
	scanf("%d",&n);
	
	t=n;
	do  //Using do while loop to check if sum is a single digit number. If it is single digit we stop else we enter in the loop again.
	{
		s=0;
		while(t!=0) //Extracting digits of a number
		{   
			r=t%10;
			s+=r;   //finding the sum of digits
			t=t/10;
		}
		t=s;   //assigning sum's' to 't' for next iteration . 
	}
	while(s/10 !=0);
	printf("%d \n",s);
	return 0;
}
