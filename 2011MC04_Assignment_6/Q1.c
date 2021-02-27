//Avinash Singh 2011MC04
//Question no 1
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
As per the question, plesae give the following as input.
Input:

Dimension: 3 5 
Matrix: 
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Defining a Queue node

struct QNode 
{ 
	int i;
	int j; 
	struct QNode* next; 
}; 

//Defining a Queueu
struct Queue 
{ 
	struct QNode *front, *rear; 
}; 

// A function to create a new linked list node. 
struct QNode* newNode(int a,int b) 
{ 
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
	temp->i = a; 
	temp->j = b;
	temp->next = NULL; 
	return temp; 
} 

// A function to create an empty queue 
struct Queue* createQueue() 
{ 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 

// The function to add a pair(i,j) to q 
void enQueue(struct Queue* q, int a, int b) 
{ 
	// Create a new LL node 
	struct QNode* temp = newNode(a,b);
	 
	// If queue is empty, then new node is front and rear both 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 

	// Add the new node at the end of queue and change rear 
	q->rear->next = temp; 
	q->rear = temp; 
} 


// Function to remove a key from given queue q 
void deQueue(struct Queue* q) 
{ 
	// If queue is empty, return NULL. 
	if (q->front == NULL) 
		return; 

	// Store previous front and move front one node ahead 
	struct QNode* temp = q->front; 

	q->front = q->front->next; 

	// If front becomes NULL, then change rear also as NULL 
	if (q->front == NULL) 
		q->rear = NULL; 

	free(temp); 
} 



//Main()
int main()
{
int n,m,i,j,flag=0;
printf("Enter the dimension of the matrix N x M \n\n");
scanf("%d %d",&n,&m);
int mat[n+1][m+1];
printf("Enter the values between (0-2) to fill the matrix \n\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
	scanf("%d",&mat[i][j]);	
	}
}
printf("Received your Input \n\n");
printf("You have entered : \n\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
	printf("%d",mat[i][j]);	
	}
	printf("\n");
}

struct Queue* q = createQueue(); 
printf("Queue created \n\n");

for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
		if(mat[i][j]==2)
		{
		enQueue(q,i,j);       //Pushing the index of 2's 
		}
	
	}
}

struct QNode* temp = q->front;
printf("The Indices stored in the queue are : \n");
while(temp!=NULL)
{
printf("You inserted [ %d,%d ]\n",temp->i,temp->j);	
temp=temp->next;
}

//Here we extract elements from the queue and convert it's adjacent 1's to 2 and store them back in Queue.
int l=0;
while(q->rear!=NULL)
{
	printf("Level %d \n\n",l);
    int count=0,qsize;
    struct QNode* temp = q->front;
    while(temp!=NULL)
    {
        count++;
        temp = temp -> next;
    }
    printf("Queue Size : %d \n\n",count);
	qsize = count;
		while(qsize--)
		{
			int a,b;
			a=q->front->i;
			b=q->front->j;
			deQueue(q);	
			if(a>1 && mat[a-1][b]==1) 
			{
			flag=1;
			mat[a-1][b]=2;
			enQueue(q,a-1,b);		
			printf(" You inserted %d,%d \n",q->rear->i,q->rear->j );
			}
			
			if(a<n && mat[a+1][b]==1)
			{
			flag=1;
			mat[a+1][b]=2;
			enQueue(q,a+1,b);	
			printf(" You inserted %d,%d \n",q->rear->i,q->rear->j );	
			}
		
			if (b>1&& mat[a][b-1]==1)
			{
			flag=1;
			mat[a][b-1]=2;
			enQueue(q,a,b-1);
			printf(" You inserted %d,%d \n",q->rear->i,q->rear->j );		
			}
			
			if(b<m && mat[a][b+1]==1)
			{
			flag=1;
			mat[a][b+1]=2;
			enQueue(q,a,b+1);
			printf(" You inserted %d,%d \n",q->rear->i,q->rear->j );		
			}
		}
	l++;
}

if(flag==0)
{
printf("Not Possible : -1 \n\n");
}
else
{
printf("Minimum Time required = %d seconds \n\n",l-1);
printf("FinalMatrix : \n\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
	printf(" %d ",mat[i][j]);	
	}
	printf("\n");
}
}

return 0;	
}
