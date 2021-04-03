//2011MC04 Avinash Singh 

#include <stdio.h>
#include <limits.h>

//-------------------------------------------------------------------------------------------------------------------//
/* TEST CASE Adjacency Matrix

0  10  0   30   100
10  0  50  0    0
0   50  0  20   10
30   0  20   0   60
100 0  10  60   0

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
    printf("%d ", j);
}



//Defining  Dijkstra's Shortest Path Algorithm [DjSPA]  with Single Source 

void DjSPA(int src,int V,int dest,int graph[V][V])
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
		printf("The Shortest Route to go from %d to %d is : \n",src,dest);
	    printf("\nVertex\t\t Distance\tPath");
	    for (i = 0; i < V; i++)
	    {
	    	
	    	if(i==dest)
	    	{
		    printf("\n%d -> %d \t\t %d\t\t%d ",sr, i, Distance_Array[i], sr);
		    Shortest_Route(parent, i); 
		    }
	}
			
}


// Main()
int main()
{
    int source,dest,i,j,V;
	printf("Enter the number of vertices in the Graph \n");
	scanf("%d",&V);
	int graph[V][V];
	printf("Enter the number of adjacency Matrix of the Graph \n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter the Source Node and Destination Node \n");
	printf("Enter Source Node \n");
	scanf("%d",&source);
	printf("Enter Destination Node \n");
	scanf("%d",&dest);
	DjSPA(source,V,dest,graph);
	return 0;
}

