//Avinash Singh 2011MC04 
#include <stdio.h>
int main()
{
int n,sum=0,x;
scanf("%d",&n);
while(n!=-99)    //Keep executing the loop untill number -99 is received as input
	{
		sum+=n;
		scanf("%d",&x); //receive a number as input
		n=x;
	}
printf("Sum=%d",sum); //Printing the sum
return 0;
}


