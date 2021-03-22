/* Avinash Singh 2011MC04 */
/*
For the GIVEN TEST CASE IN the  QUESTION,
Copy and Paste the lines below to get the OUTPUT:

37
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9 
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

//Delaring the Adjacency matrix
int adj[3000][3000]={0};

//Declaring a structure of an edge
struct EDGE_DATA{
	float E_weight;
	int node1,node2;
};

typedef struct EDGE_DATA EDGE_DATA;

//sorting Function : To Sort the weights of the edges
/* Swapper */ 
void swap(EDGE_DATA *a,EDGE_DATA *b){
    EDGE_DATA temp=*a;
    *a=*b;
    *b=temp;
}

//Choosing last element as pivot in Partition Function
int sort_part(EDGE_DATA a[],int l,int h)
{
    float pivot=a[h].E_weight;
    int i=l,j;
    for(j=l;j<h;j++){
        if(a[j].E_weight>pivot){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    swap(&a[i],&a[h]);
    return i;
}

void sort(EDGE_DATA a[],int l,int h)
{
    if(l<h){
        int p=sort_part(a,l,h);
        sort(a,l,p-1);
        sort(a,p+1,h);
    }
}


//DFS Function : Required to check if graph is connected or Not !
void Depth_First_Search(int v,int node,int visited[]){
	visited[node]=1;
	int i;
	for(i=0;i<v;i++){
		if(adj[node][i]!=0){
			if(visited[i]==0){
				Depth_First_Search(v,i,visited);
			}
		}
	}
}

//Checking Connectivity of the Graph !
int Graph_Connectivity(int v)
{
	int visited[v],i;
	for(i=0;i<v;i++)
		visited[i]=0;
	visited[0]=1;
	for(i=0;i<v;i++){
		if(adj[0][i]!=0){
			if(visited[i]==0){
				Depth_First_Search(v,i,visited);
			}
		}
	}
	int Continuous=1;
	for(i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			Continuous=0;     // return 0 if graph is not connected
			break;
		}
	}
	return Continuous;
}

/* Main() */ 

int main(){
	int v,node1,node2;
	float E_weight;
	printf("\n Enter Total Budget ");
	float Maximum_Cost;
	scanf("%f",&Maximum_Cost);
	printf("\n Enter the total number of vertices in the graph :\n");
	scanf("%d",&v);
	int e;
	int i,j,v_i=1;
	while(v_i)
	{
		printf("\nEnter the number of edges in the graph ");
		scanf("%d",&e);
		if(e>(v*(v-1)/2) || e<0){
			printf("\nInvalid input");
		}else
			v_i=0;
	}
	
	float total_sum=0;
	EDGE_DATA* Edge_List=(EDGE_DATA*)calloc(e, sizeof(EDGE_DATA));;
	for(i=0;i<e;i++){
		printf("\n Enter the Edge Details in the format source_node, Destination_node, Edge_Weight \n");
		scanf("%d",&node1);
		scanf("%d",&node2);
		scanf("%f",&E_weight);
		if(adj[node1][node2]!=0){
			printf("\n Edge Already exists");
			i--;
			continue;
		}	
	
		if(node1<0 || node1>=v || node2<0 || node2>=v || E_weight==0){
			printf("\nInvalid input");
			i--;
			continue;	
		}
		adj[node1][node2]=E_weight;
		adj[node2][node1]=E_weight;
		Edge_List[i].E_weight=E_weight;
		Edge_List[i].node1=node1;
		Edge_List[i].node2=node2;
		total_sum+=E_weight;

	}
	if(!Graph_Connectivity(v))
	{
		printf("\n Graph is Disconnected , Algorithm cannot continue!\n");
		return 0;
	}
	
	//Sorting edge weights in the Decreasing order
	sort(Edge_List,0,e-1);
	
	//Deleting Max_weight edge if condition is satisfied
	float TEMP_WT;int flag=0;
	for(i=0;i<e;i++){
		if(total_sum<=Maximum_Cost){
			flag=1;
			break;
		}
		TEMP_WT=Edge_List[i].E_weight;
		node1=Edge_List[i].node1;
		node2=Edge_List[i].node2;
		
		//Deleting the Edge
		adj[node1][node2]=0;
		adj[node2][node1]=0;
		if(!Graph_Connectivity(v)){
			//Undo Edge Deletion since graph becomes disconnected
			adj[node1][node2]=TEMP_WT;
			adj[node2][node1]=TEMP_WT;
		}
		else
		{
			//We Reduce the total sum  if we find that after deletion graph is still connected
			total_sum-=TEMP_WT;
		}
	}
	if(flag==1)
	{
		printf("\n Total Cost incurred %f \n",total_sum);
		printf("\n The  minimum weight edges in the graph are :");
		printf("\n node1  node2  E_weight");
		for(i=0;i<e;i++){
			TEMP_WT=Edge_List[i].E_weight;
			node1=Edge_List[i].node1;
			node2=Edge_List[i].node2;
			if(adj[node1][node2]==0)
				continue;
			else{
				printf("\n %d   %d   %f",node1,node2,TEMP_WT);
			}
		}
	}
	else
	{
		printf("\n Cost Exceeded the Minimum Budget ",Maximum_Cost);
	}
	printf("\n");
	return 0;
}
