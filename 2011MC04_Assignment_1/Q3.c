//Avinash Singh 2011MC04 
#include <stdio.h>
int main()
{
int i=1,n;              //Variable Declaration
float sum=0.0,temp=0.0; //Variable Declaration
printf("\nEnter a number ");
scanf("%d",&n);
while(i<n)                 
{
printf(" 1/%d +",i);    //Printing the Harmonic Series
sum+=1/(float)i;        //Calculating the Sum of the series
i++;
}
printf(" 1/%d",i);
sum+=1/(float)i;
printf("\n Sum is %f",sum); //Printing the Sum
return 0;
}
