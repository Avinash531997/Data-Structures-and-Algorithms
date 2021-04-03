//2011MC04 Avinash Singh 

#include <stdio.h>
#include <limits.h>

//-------------------------------------------------------------------------------------------------------------------//
/* TEST CASE 
4 4 2 2 
1 2 1
2 3 3 
3 4 2 
4 1 1 
2 4 
3 
2 
*/

// Function to Find the vertex with minimum distance value,from the vertices not included in the shortest path yet!

int Closest_Vertex(int Distance_Array[], int ShortPathSet[],int V)
{
	int min = INT_MAX, min_vertex_position,v;

	for (v = 0; v < V; v++)
		if (ShortPathSet[v] == 0 && Distance_Array[v] <= min)
			min = Distance_Array[v], min_vertex_position = v;
	return min_vertex_position;
}

void Shortest_Route(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    Shortest_Route(parent, parent[j]);
    printf("%d ", j+1);
}


//Defining  Dijkstra's Shortest Path Algorithm [DjSPA]  with Single Source 


void DjSPA(int src,int V,int graph[V][V],int center[V])
{
	int Distance_Array[V];  //  Distance_Array[i] to store the shortest distance from source to vertex i.

	int ShortPathSet[V];    // ShortPathSet[i] = 1 if vertex i is included in ShortestPathSet, else 0. 
	
	int parent[V];
	
	int i,iterate,v;;
	for (i = 0; i < V; i++)
		Distance_Array[i] = INT_MAX, ShortPathSet[i] = 0,parent[src] = -1;    //Initially Value of all node is initialized to INFintiy(A Maximum Value).

	// Considering the distance of source vertex from itself as  0
	Distance_Array[src] = 0;
	

	// Calculating the shortest path for all vertices
	for (iterate = 0; iterate < V - 1; iterate++) 
	{
		
		int u =Closest_Vertex(Distance_Array, ShortPathSet, V);

		// The picked vertex is marked as visited
		ShortPathSet[u] = 1;

		// Updating the Distance_Array value for the adjacent vertices of the currently picked vertex.
		for (v = 0; v < V; v++)
			if (!ShortPathSet[v] && graph[u][v] && Distance_Array[u] != INT_MAX && Distance_Array[u] + graph[u][v] < Distance_Array[v])
				{
				parent[v] = u;
				Distance_Array[v] = Distance_Array[u] + graph[u][v];
				}
	}
	//Printing the Required Shortest Path
		int sr = src;
		//printf("The Shortest Route to go from %d to %d is : \n",src,dest);
	    printf("\nVertex\t\t Distance\tPath");
	    for (i = 0; i < V; i++)
	    {
		    printf("\n%d -> %d \t\t %d\t\t%d ",sr+1, i+1, Distance_Array[i], sr+1);
		    Shortest_Route(parent, i); 
		}
		int min,min_index;
		min=INT_MAX;
		for (i = 0; i < V; i++)
	    {
		   if(Distance_Array[i]<min && center[i]==1)
		   {
			   	min=Distance_Array[i];
			   	min_index=i; 
		   }
		}
		int d;
		d=Distance_Array[min_index];
		if(d==0)
		d=0;
		printf("\n Nearest Exam Center is %d \n ",min_index+1);
		printf("\n Distance between city %d to city %d = %d   ", sr+1,min_index+1,d);
		
}
			



// Main()
int main()
{
    int source,dest,i,j,V,M,K,Q,un,vn,W;
	printf("Enter the number of cities (N) ,  number of roads  (M) , number of exam centers  (K) , number of Queries  (Q) \n");
	scanf("%d",&V);
	scanf("%d",&M);
	scanf("%d",&K);
	scanf("%d",&Q);
	int graph[V][V];
	int center[V];
	for(i=0;i<V;i++)
	center[i]=0;
	
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			graph[i][j]=0;
		}
	}
	for(i=0;i<M;i++)
	{
	printf("Enter three space separated integers U,V and W which such that  there is a road of length W connecting cities U and V \n");
	scanf("%d",&un);
	scanf("%d",&vn);
	scanf("%d",&W);	
	graph[un-1][vn-1]=W;
	graph[vn-1][un-1]=W;
	}
	printf("Enter Exam Centers Name \n");
	int x;
	for (i=0;i<K;i++)
	{	
	scanf("%d",&x);	
	center[x-1]=1;
	}
	for(i=0;i<Q;i++)
	{
		printf("\n\n Enter Vinay's Home City,  (Q[%d]) \n",i+1);
		scanf("%d",&source);
		DjSPA(source-1,V,graph,center);
	}
	
	return 0;
}

