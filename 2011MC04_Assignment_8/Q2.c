/*
Avinash Singh 2011MC04 
*/

#include<stdio.h>
#include<math.h>

//Subroutine to return the Maximum element in the array !
int Maximum_value(int arr[], int n) 
{ 
	int MAXX = arr[0];
	int i; 
	for (i = 1; i < n; i++) 
		if (arr[i] > MAXX) 
			MAXX = arr[i]; 
	return MAXX; 
} 


//Supporting Sub Routine of Counting Sort
void COUNT_SORT(int arr[], int n, int digit_POS) 
{ 
	int Modified_arr[n];   
	int i, count[10] = { 0 }; //Declaring an array of size 10 representing digit 0-9.
	for (i = 0; i < n; i++) 
		count[(arr[i] / (int) (pow(10,digit_POS)) )% 10]++;  // Storing the  count of occurrences in count[] array  
	for (i = 1; i < 10; i++) 
		count[i] += count[i-1];   // Modifying count[i] such that it contains actual position of the digit in Modified_arr[]  
	for (i = n - 1; i >= 0; i--) { 
		Modified_arr[count[(arr[i] / (int)pow(10,digit_POS)) % 10] - 1] = arr[i];  	// Modified array
		count[(arr[i] / (int)(pow(10,digit_POS))) % 10]--; 
	} 

	// we will now copy the Modified_arr array to arr[], so that arr[] contains numbers sorted according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = Modified_arr[i]; 
} 


// Radix Sort 
void RADIX_SORT(int arr[], int n) 
{ 
	// Finding the number of digits 
	int m = Maximum_value(arr, n);  
	int maxpos=log10(m);
	int digit_POS;
	for (digit_POS = 0;digit_POS<=maxpos; digit_POS+=1) 
		COUNT_SORT(arr, n, digit_POS);  //Calling CountSort
} 


//Main()

int main() 
{ 
	int n;
	printf("Enter the length of an array \n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	RADIX_SORT(arr, n); 
	printf("Array after applying Radix sort : \n");
	for (i = 0; i < n; i++) 
		 printf("%d ",arr[i]); 
	return 0; 
}

