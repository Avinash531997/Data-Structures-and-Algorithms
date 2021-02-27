//Avinash Singh 2011MC04
//Note: Queue follows FIFO where as stack follows LIFO .
//In the code below , I have just made a slight change where I am removing item from the rear end instead of front end of queue datastructure.
//This makes it LIFO which is a stack !
//And finally following the BFSearch algorithm but using a Stack !
/*----------------------------------------------------------------------------------------------------------------------------------------------------------
As per the Question given , please give the following as input.
Input: Number of vertices =5

Copy and paste it!
Adjacency matrix :
0 1 1 1 0 
1 0 1 0 0 
1 1 0 0 1 
1 0 0 0 0 
0 0 1 0 0 
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<conio.h>

//Defining the BFSearch function
void BFSearch(int a[10][10], int n, int u)
{
   int f,r,q[10],v,s[10]={0};
   printf("\n The nodes visited from %d are: ",u);
   
   f=0, r=-1;  // Declaring 2 pointers f->front r->rear
   q[++r]=u;   //Inserting  element at rear end.
   s[u]=1;     // Marking  u as visited node.
   while(f<=r)        //if front is less than or equal to rear i.e if queue is non empty
   {
   	printf("%d ",q[r]); //Printing the rear element which we will be exploring and then we will delete it.
	u=q[r];
	r--;               // Delete an element from Queue  <But we will  delete from rear end to make it LIFO i.e a Stack>
	for(v=0;v<n;v++)
	{
		if(a[u][v]==1)      // Detecting edge
		{
			if(s[v]==0)     // if v has not been visited
			{
				
				s[v]=1;              // Marking v as visited
				q[++r]=v;            // Inserting v into Queue
			}
		}
	}
}
printf("\n");
}

//Define main()
int main()
{
   int n,a[10][10],i,j,Initial_vertex;
   printf("\nEnter the number of nodes in the graph : ");
   scanf("%d",&n);
   printf("\nEnter the Adjacency Matrix corresponding to the graph : \n");
   for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	printf("Enter the initial vertex \n");
	scanf("%d",&Initial_vertex);
	BFSearch(a,n,Initial_vertex);
return 0;
}



