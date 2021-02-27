//Avinash Singh 2011MC04 
#include <stdio.h>
#include<math.h>
int main()
{
int num,t,n=0,r,s=0; //Variable Declaration
printf("\nEnter a number ");
scanf("%d",&num);
t=num;
while(t!=0)
{
	r=t%10;
	n++;   //counting the number of digits in the number
	t=t/10;
}
t=num;
while(t!=0)
{
	r=t%10;
	s=s+(pow(r,n)); //Finding the sum of each digits of the number raised to the power 'n'
	t=t/10;
}
if(s==num)
printf("Armstrong Number");
else
printf("Not an Armstrong Number");
return 0;
}
