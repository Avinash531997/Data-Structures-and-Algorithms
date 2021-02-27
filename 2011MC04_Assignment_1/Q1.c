//Avinash Singh 2011MC04 
#include <stdio.h>
int main()
{
int n,count=0;         //Variable Declaration 
printf("\nEnter a number ");            
scanf("%d",&n);
    if(n<1)            //if n is less than 1 we print Error
    {
    printf("Error");
    }
    printf("Initial value is %d \n",n);
    while(n!=1)      //Enter into while loop if n is not equal to 1
    {
        count++;
        if(n%2==0)  //Check if n is even
        {
        n=n/2;
        printf("Next value is %d \n",n);
        }
            else   //if n is odd
            {
            n=3*n+1;
            printf("Next value is %d \n",n);
            }
    }
    printf("Number of steps %d",count);
return 0;
}

