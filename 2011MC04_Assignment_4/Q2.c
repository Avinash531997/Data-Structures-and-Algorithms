//Avinash Singh 2011MC04
//NOTE: Create a link list first. Then using CASE:6 We can check if there is a loop in the linked list or not.

#include<stdio.h>
#include<stdlib.h>

//Defining Node Structure

struct node                
{ 
    int value;             
    struct node *next;     
};


struct node *head; 
void initialize()
{
    head=NULL;    //initializing the head of the linked list to NULL
}

//Inserts element in the front of the linked list
void insert_front(int element)   
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));    
    New->value=element;      
    New->next=NULL;           
    New->next=head;         
    head=New;              
}

//Inserts an element afer a specific element in the linked list
void insert_specific(int elem, int num)  
{
    struct node* New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=elem;
    New->next=NULL;
    struct node* prev=head;
    while(prev->value!=num)
    {
        prev=prev->next;
    }
    New->next=prev->next;
    prev->next=New;
}

//inserts element at the end of the linked list
void insert_end(int ele)   
{
    struct node *New, *temp;
    New = (struct node*)malloc(sizeof(struct node));
    if(New== NULL)
    {
        printf("Meomory Insufficeint \n");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("Data Insertion Successful \n");
    }
}

//Deletes the first element from the linked list
void delete_first()    
{
    struct node* cur;
    if(head==NULL)
        printf("list is empty and nothing to delete \n");
    cur=head;
    head=head->next;
    free(cur);
}

//deletes the last element of the linked list
void delete_end()   
{
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev->next!=NULL)
        prev->next=NULL;
    free(cur);
}

//Deletes a specific element from the linked list
void deleteitem(int ele)
{
    if(head==NULL)
    printf("list is empty and nothing to delete \n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    prev->next=cur->next;       
    free(cur); //Release the memory used by the deleted node                     
}


//Search if an element is present in the linked list
int searchdata(int ele)
{
    struct node* temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->value == ele)
            return 1 ;          //element is found
		temp = temp->next;
	}
	return 0 ;
}

//Updates a specific element in the linked list
int updateitem(int ele, int key)
{
    struct node* temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->value == ele)
		{
		temp->value=key;
        return 1 ;
		}          //element is found
		temp = temp->next;
	}
	return 0 ;
}

//Display all the elements in the linked list
void print()
{
    if(head==NULL)    //check if list is empty
    {
        printf("list is empty \n");
        return;
    }
    struct node *cur=head;            
    int count;
    count=0;
    while(cur!=NULL)                 
    {
        printf("%d->",cur->value);    
        count++;                      
        cur=cur->next;                
    }
    printf("NULL\n");
    printf("number of nodes %d \n",count);
}

//Floyd’s Cycle Detection Technique implemented below using a slow and a fast pointer to detect a cycle in the linked list
int loopdetector()
				{
				    struct node *ptr1 = head;   //Slow Pointer
					struct node *ptr2 = head;   //Fast Pointer
				    while (ptr2 != NULL && ptr2->next != NULL)
				    {
				        ptr1 = ptr1->next;        //Slow pointer taking 1 step
				        ptr2 = ptr2->next->next;  //Fast Pointer taking 2 steps
				        if (ptr1 == ptr2)
				            return 1;
				    }
				    return 0;
				}



int main()
{
    initialize();
    int choice;
	while(1)
	{
	printf("1. Add a node before/after a specific node (with specific data)\n");
	printf("2. Delete a node before/after a specific node (with specific data)\n");
	printf("3. Search a node with specific data whether present or not.\n");
	printf("4. Update data filled of a specific node (with specific data)\n");
	printf("5. Print data stored in each node \n");
	printf("6. Cycle Detection \n");
	printf("7. Exit the Process \n");
	printf("Enter Your Choice :) \n");
	scanf("%d",&choice);
	system("cls");     //included this function to keep the output screen clear after every choice selection
	switch(choice)
	{
		
		case 1: printf("Enter element to insert\n");
				int element;
				scanf("%d",&element);
				printf("1. Insert in the Front \n");
				printf("2. Insert in the End   \n");
				printf("3. Insert after a Node \n");
				int ch;
				scanf("%d",&ch);
				if(ch==1)
				insert_front(element);
				else if(ch==2)
				insert_end(element);
				else if(ch==3)
				{
				printf("Enter element after which you want to insert\n");
				int key;
				scanf("%d",&key);
				insert_specific(element,key);
				}
				else
				printf("Invalid Choice \n");
				break;
		case 2: printf("1. Delete from  the Front \n");
				printf("2. Delete from  the End   \n");
				printf("3. Delete a specific element\n");
				int ch2;
				scanf("%d",&ch2);
				if(ch2==1)
				delete_first();
				else if(ch2==2)
				delete_end();
				else if(ch2==3)
				{
				printf(" Enter element you wish to delete \n");
				int delkey;
				scanf("%d",&delkey);
				deleteitem(delkey);
				}
				else
				printf("Invalid Choice\n");
				break;
				
		case 3: printf("Enter data to be searched\n");
				int data;
				scanf("%d",&data);
				if(searchdata(data))
				printf("Data found \n");
				else
				printf("Data not found\n");
				break;
				
		case 4: printf("Enter Node to update \n");
				int ele2,key2;
				scanf("%d",&ele2);
				printf("Enter data to be inserted at node\n",data);		
				scanf("%d",&key2);
				if(updateitem(ele2,key2))
				printf("Updated");
				else
				printf("Invalid node accessed\n");
				break;
		case 5: print();
				break;
		case 6: head->next->next->next->next = head;    
				/*
				// I have deliberately created a loop using the line above.
				So it will detect the loop. If we remove this line then 
				link list will not have any cycle so no loop will be detected.
				*/
				if(loopdetector())                      // if loopdetector() returns 1 , it means loop is present else no loop present.
				printf("Loop Detected \n");
				else
				printf("No Loop Detected \n");
				break;
		case 7: exit(0);
		default:printf("Invalid Choice :( \n");
	}
	
}
    	return 0;

}

