//2011MC04 Avinash Singh

/*Test Case Input :
2
5 6
1 2 2
2 3 -1
3 4 -7
4 5 0
2 3 -7
3 5 6
5 8
1 5 10
2 3 -6
5 2 5
4 5 9
1 5 1
2 4 -10
2 3 -2
4 1 1
*/


#include <stdio.h>
#include<limits.h>

//Finding Minimum Value
int Minimum_Value(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

int I[1000],J[1000],C[1000];
int N,M;

//Funcion to Detect Negative Cycle
int Negative_Cycle_Detector()
{
	int Distance_Array[N];  //Initialization
	int i,j;
	for(i=0;i<N;i++)
	Distance_Array[i]=INT_MAX; //Initializing all node values to Infinity(MAX-Value)
	Distance_Array[0]=0;       //Initializing Source node value to 0
	for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	if(Distance_Array[I[j]]!=INT_MAX)
	Distance_Array[J[j]]=Minimum_Value(Distance_Array[J[j]],C[j]+Distance_Array[I[j]]);
	for(j=0;j<M;j++)
	if(Distance_Array[I[j]]!=INT_MAX && Distance_Array[J[j]]>Distance_Array[I[j]]+C[j])
			 return 1;
	return 0;
}

//Main()
int main()
{
	int T;
	printf("Enter the Number of Test Cases \n");
	scanf("%d",&T);
	while(T--)
	{
		printf("Enter two space-separated integers N, M \n");
		scanf("%d %d",&N,&M);
		int i;
		for(i=0;i<M;i++)
		{
			printf("Enter the Characteristics of the Traders \n");
			scanf("%d %d %d",&I[i],&J[i],&C[i]);
			I[i]=I[i]-1;
			J[i]=J[i]-1;
			C[i]=(-1)*C[i];
		}
		if(Negative_Cycle_Detector()) //Checking if negative Cycle is formed.
		printf("Yes\n");
		else
		printf("No\n");
	}
    
    return 0;
}
