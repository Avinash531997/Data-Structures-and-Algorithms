//Avinash Singh , 2011MC04
#include<stdio.h>
#include<conio.h>
//We will use mergesort to sort the array.
//Then finally we will return kth smallest element

//Defining the Function merge 
void merge(int a[],int l, int m,int r)
{
	int n1,n2;
	n1=(m-l)+1;
	n2=(r-m);
	int x[n1],y[n2],i,j;
	for (i = 0; i < n1; i++)
        x[i] = a[l + i];
    for (j = 0; j < n2; j++)
        y[j] = a[m + 1 + j];
        
	i = 0; 
    j = 0; 
    int k = l; 
    while (i < n1 && j < n2) 
	{
        if (x[i] <= y[j]) 
		{
            a[k] = x[i];
            i++;
        }
        else 
		{
            a[k] = y[j];
            j++;
        }
        k++;
    }
 
    //Copy the remaining elements of x[]
    while (i < n1) 
	{
        a[k] = x[i];
        i++;
        k++;
    }
 
    //Copy the remaining elements of y[]
    while (j < n2) 
	{
        a[k] = y[j];
        j++;
        k++;
    }
}


//Defining the function mergesort 
void mergesort(int a[],int l, int r)
{
	int m;
	if(l<r)
	{
	m=(l+r)/2;
	mergesort(a,l,m);   //Recursive call of mergesort on left subarray
	mergesort(a,m+1,r); //Recursive call of mergesort on right subarray
	merge(a,l,m,r);     //calling the merge function to merge two sorted array
	}
}

int main()
{
	int n,k;
	printf("Enter length of array followed by the number k ");  //take n and k as  inputs
	scanf("%d %d",&n,&k);
	int i,a[n],l=0,r=n-1;
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);  //take the array as input
	mergesort(a,l,r);   //Calling the mergesort function
	printf(" %d th smallest element is %d \n",k,a[k-1]);
return 0;
}

