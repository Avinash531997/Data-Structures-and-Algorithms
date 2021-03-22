/* Avinash Singh 2011MC04 */ 

#include <limits.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* Variable Declaration */
int i,j,k,a,b,u,v,g_nodes,ne=1,g_edges=0,x,y,wt;
int min,MINIMUM_COST=0,NET_COST[3000][3000],PARENT[3000];

/* Function Declaration */
int FIND_Function(int);
int UNION_Function(int,int);

/* Main()*/
int main()
{
 printf("\nEnter the no. of vertices and edges\n");
 scanf("%d %d",&g_nodes,&g_edges); 
 printf("\nEnter the details of edge in the format :  Source_node, Destination_node, Edge_weight\n");
 
 
 /*Entering the Edge Details*/
 for(i=1;i<=g_edges;i++)
 {
    printf("Edge %d \n",i);
 	scanf("%d",&x);
 	scanf("%d",&y);
 	scanf("%d",&wt);
 	NET_COST[x][y] =wt;
 	NET_COST[y][x] =wt;
 }
 
 /*Making the values in the lower triangular matrix 0*/
 
 for(i=1;i<=g_nodes;i++)
 {
  for(j=1;j<i;j++)
  {
  	NET_COST[i][j]=0;
  }
 }
 
/* Now focusing on the matrix , if any element is found to be 0, it indicates no edge present between the corresponding vertices. Hence make the value INT_MAX.*/ 
 for(i=1;i<=g_nodes;i++)
 {
  for(j=1;j<=g_nodes;j++)
  {
   if(NET_COST[i][j]==0)
    NET_COST[i][j]= INT_MAX;
  }
 }
 
printf("\nThe edges of the  Minimum Cost Spanning Tree are \n");
while(ne<g_nodes)
{

/* The code segment below help's to FIND_Function out the minimum weight edge */
min=INT_MAX;
for(i=1;i<=g_nodes;i++)
	{
	for(j=1;j<=g_nodes;j++)
		{
		if(NET_COST[i][j]<min)
			{
			 min=NET_COST[i][j];
			 a=u=i;
			 b=v=j;
			}
		}
	}
  
  u=FIND_Function(u);
  v=FIND_Function(v);
  if(UNION_Function(u,v))
  {
   printf("\n%d edge [%d,%d] =%d\n",ne++,a,b,min);
   MINIMUM_COST +=min;
  }
  NET_COST[a][b]=NET_COST[b][a]=INT_MAX;
 }
 printf("\n Minimum NET_COST = %d\n",MINIMUM_COST);
 return 0;
}

/* Cycle Detection using FIND_Function + Union Technique */
int FIND_Function(int i)
{
 while(PARENT[i])
  i=PARENT[i];
 return i;
}


int UNION_Function(int i,int j)
{
 if(i!=j)
 {
  PARENT[j]=i;
  return 1;
 }
 return 0;
}


