//Avinash Singh
//2011MC04

/*
Given TEST CASES :

1 6 3 4 5 2 7

1 6 3 4 5 7 2

*/

#include<stdio.h>
#include<conio.h> 

//Function to Swap
void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}

//Quick Sort Function

void QuickSORT(int arr[], int low, int high) 
{ 

	if (low < high) 
	{ 
	
	//Partition Section : We do the Partition here considering the middle element as pivot
	int pip = (low+high)/2;                      
	int pivot = arr[pip];                        //considering the middle element as pivot
	int left,right;
	left=low;
	right=high;
	
	//The block of code below helps us to get 2 proper partitions such that left partition has all elements <= pivot and right partition has elements >= pivot.
	
	while(left <= right) 
	{
		while(arr[left] < pivot) 
		left++;
		while(arr[right] > pivot) 
		right--;
		if(left <= right) 
		{
			swap(&arr[left],&arr[right]);
			left++;
			right--;
		}		
	}

	QuickSORT(arr, low,right);     //Applying QuickSORT to Left Partition
	QuickSORT(arr, left, high);    //Applying QuickSORT to Right Partition
	
	} 
} 

//Main Function
int main() 
{  
 	int n;
 	printf("Enter the length of an array\n");
 	scanf("%d",&n);
	int arr[n],arr2[n],i;
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	arr2[i]=arr[i]; //Making a copy of the original array
	
	QuickSORT(arr2, 0, n - 1);   //Calling the QuickSORT Function here !
	
	for (i = 0; i < n; i++) 
	{
  
        /*
        comparing each element of the sorted array (arr2[])  with equivalent element of original array(arr[]) and its mirror image when pivot around center 
		*/
        if ((arr[i] != arr2[i]) && (arr[n - 1 - i] != arr2[i]))
            {
            	printf("NO \n");
				return ;
			}
    }
    printf("YES \n");
	return 0; 
}


