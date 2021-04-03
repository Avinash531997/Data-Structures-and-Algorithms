//2011MC04 
//Avinash Singh 
#include<stdio.h>
#include<conio.h>
#include<limits.h>

//Returning the Maximum of the Two Values
int Maximum(int a, int b) 
{ 
if(a>b)
return a;
else 
return b;
}

//Slicing the mirror at different points and returning maximum value from an optimal cut.
int Mirror_Slicing(int cost[], int n)
{
   int i;
   if (n <= 0)
     return 0;
   int maximum_value = INT_MIN;
   for (i = 0; i<n; i++)
   {
    maximum_value = Maximum(maximum_value, cost[i] + Mirror_Slicing(cost,n-i-1));  //Recursive calling of the function Mirror_Slicing
   }
   return maximum_value ;
}

//Main()
int main()
{
	
int n,i;
printf("Enter the maximum possible length of the item : \n");
scanf("%d",&n);
int cost[n];

for(i=0;i<n;i++)
{
 cost[i]=0;
}

printf("Enter the price corresponding to the lengths separated by spaces : \n");
for(i=0;i<n;i++)
{
	scanf("%d",&cost[i]);
}

printf("Maximum Earning Possible is %d", Mirror_Slicing(cost,n));
return 0;
}





