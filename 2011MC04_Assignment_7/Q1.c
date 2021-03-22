//Avinash Singh 2011MC04
//Quick Sort with Middle element as Pivot

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
	int arr[n],i;
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	QuickSORT(arr, 0, n - 1);   //Calling the QuickSORT Function here !
	printf("Sorted Array is :");
	for(i=0;i<n;i++)
	printf(" %d ",arr[i]);
	return 0; 
}


