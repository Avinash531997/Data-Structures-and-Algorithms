//Avinash Singh 2011MC04
#include<stdio.h> 
#include<conio.h>
#include<string.h> 

//Heap Sort Code: 

int temp;  
//Function Heapify:
void HEAPIFY(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
arr[i]= arr[largest];   
arr[largest] = temp;  
HEAPIFY(arr, size, largest);  
}  
}  

//Function HeapSort:
void HEAPSORT(int arr[], int size)  
{  
int i;  
for (i = size / 2 - 1; i >= 0; i--)  
HEAPIFY(arr, size, i);  
for (i=size-1; i>=0; i--)  
{  
temp = arr[0];  
arr[0]= arr[i];   
arr[i] = temp;  
HEAPIFY(arr, i, 0);  
}  
}  
  
//Main Function
int main()  
{  
//Initialization of necessary variables:
int t;
printf("\nEnter the number of Test Cases\n");
scanf("%d",&t);
while(t!=0) 
{
	t--;
	char str[10000];
	int i,l,k,TP[200],TA[200],ct=0;
	//Receiving Input from the user
	printf("\n\nEnter a String \n");
	scanf("%s",&str); 
	printf("Enter the value of k \n");
	scanf("%d",&k);
	l=strlen(str);
	int arr[l],arreverse[l],Encrypted[l],Decrypted[l];
	
	//Storing each character's ASCII value in an array
	for(i=0;i<strlen(str);i++)
	{
		arr[i]= (int)(str[i]);
		Encrypted[i]=(int)(str[i]);
	}
	
	int size = sizeof(arr)/sizeof(arr[0]);  
	
	//Calling HeapSort Function:
	HEAPSORT(arr, size);  
	int j=0;
	for (i=size-1; i>=0;i--) 
	{
	arreverse[j++]=arr[i];	
	}
	
	printf("\nEncrypted String:\n");
	for (i=0; i<size;i++) 
	{
	printf("%c ",Encrypted[i]);  
	}
	
	printf("\nEncrypted String Sorted in Decreasing Order\n");
	for (i=0; i<size;i++) 
	{
	printf("%c ",arreverse[i]);  
	}
	
	//Decrypted[k-1]=Encrypted[0];
	//We declare two HASH Table TP,TA to store the elements preceeding and following a letter respectively.
	for(i=0;i<200;i++)
	{
	TP[i]=0;
	TA[i]=0;	
	}
	
	//Storing the Letter following the current letter
	for(i=0;i<size;i++)
	{
	TA[Encrypted[i]]=arreverse[i];
	}
	
	//Storing the Letter preceeding the current letter
	for(i=0;i<size;i++)
	{
	TP[arreverse[i]]=Encrypted[i];
	}
	
	
	//The Sequence
	printf("\nThe Sequence to be maintained is :");
	for(i=0;i<size;i++)
	{
	printf("\n %c -> %c ",TP[arreverse[i]],TA[Encrypted[i]]);
	}
	
	//Preparing the Decrypted Message
	int pos=k-1;
	Decrypted[pos]=Encrypted[0];	
	while(pos>0)
	{
	Decrypted[pos-1]=TP[Decrypted[pos]];
	pos--;	
	}
	pos=k-1;
	while(pos<size-1)
	{
	Decrypted[pos+1]=TA[Decrypted[pos]];
	pos++;	
	}
	
	printf("\nDecrypted Message:\n");
	for(i=0;i<size;i++)
	{
	printf("%c",Decrypted[i]);
	}
}
return 0;
}  
