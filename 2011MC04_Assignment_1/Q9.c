//Avinash Singh 2011MC04 

#include <stdio.h>
int main()
{
int largest,smallest,a,b,c,i; //Variable Declaration
int arr[3];
printf("\n Enter 3 numbers");
for(i=0;i<=2;i++)
scanf("%d",&arr[i]);
a= arr[0];
b= arr[1];
c= arr[2];

largest = (a>b ? (a>c ? a : c) :(b>c ? b: c));   //Ternary operator to find the largest number
printf("largest = %d \n",largest);
smallest= (a<b ? (a<c ? a : c) :(b<c ? b: c));   //Ternary operator to find the smallest number
printf("smallest = %d",smallest);
return 0;
}


