//Avinash Singh 2011MC04 
#include<stdio.h>
int main()
{
    int i, j, k, n;  //Variable Declaration
    int a[n];
    printf("\nEnter the length of an array ");
    scanf("%d", &n);
	printf("\nEnter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
	printf("Original array is: "); // Printing the Original Array
    for(i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    for(i = 0; i < n; i++)
    {
    	for(j = i+1; j < n; )
        {
            if(a[j] == a[i])    // If Duplicate Found then enter into the loop
            {
                for(k = j; k < n; k++)  
                {
                    a[k] = a[k+1];  //Shifting elements towards left by one position and removing the duplicate at the same time
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
 printf("\nModified  array is: "); // Printing the Modified Array
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
return 0;
}
