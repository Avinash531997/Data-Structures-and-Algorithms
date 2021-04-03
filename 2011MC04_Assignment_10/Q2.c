//2011MC04 
//Avinash Singh 

#include<stdio.h>
#include<conio.h>

/*
Given Test Case :
Kindly Wait for the message on the output console and give the inputs accordingly

2 
0 1 6 4 
1 1 4 2

*/

int main()
{
    int t;
    printf("Enter the number of Test Cases");
    scanf("%d",&t);
    while(t--)
	{
        int A0,A1,N,MOD,i;
        printf("Enter A[0] : ");
		scanf("%d",&A0);
		printf("Enter A[1] :");
		scanf("%d",&A1);
		printf("Enter N :");
		scanf("%d",&N);
		printf("Enter MOD :");
		scanf("%d",&MOD);
        int A[N];
        A[0]=A0,A[1]=A1;
        int B[MOD];
        for(i=0;i<MOD;i++)
        {
        	B[i]=0;
		}
		//Array B plays a crucial role where in we are trying to keep track of the elements in increasing order.
        B[A0]++,B[A1]++;  
        for(i=2;i<N;i++)
		{
            A[i]=(A[i-1]+A[i-2])%MOD;
            B[A[i]]++;
        }
        long long int result=0;
        for(i=0;i<MOD;i++)
		{
            result+=B[i]*B[i];
        }
        printf("Maximum Possible Force : %d \n",result);
    }
    return 0;
}
