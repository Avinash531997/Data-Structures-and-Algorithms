//Avinash Singh 2011MC04
//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>

//Defining structure of a Node
struct node { 
  int data; 
  struct node *left, *right;
} ;

//Type Definition , so that we can use bst_node to represent a node pointer.
typedef struct node *bst_node;

//Function to create the first nide in the Tree
bst_node newnode(int item) 
{
  bst_node temp = (bst_node)malloc(sizeof(struct node)); 
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

//Function to insert nodes in a Tree
bst_node insertnode(bst_node node, int ele) 
{
  if(node == NULL){
    printf("Successfully inserted,\n");
    return newnode(ele);
  }
  else{    //We will do insertion such that it satisfies the property of a Binary Search Tree 
    if(ele <= node->data){
     node->left = insertnode(node->left, ele);
    }
    else if(ele > node->data){
     node->right = insertnode(node->right, ele);
    } 
    else
		printf("Element already exists in BST");
  }
  return node;
}


//Function to search a node in a Tree
bst_node searchnode(bst_node root, int ele){
	if(root == NULL || root->data == ele)
		return root;
	else if(ele > root->data)
		return searchnode(root->right, ele);
	else
		return searchnode(root->left, ele);		
}


//Function to find the minimum value node
bst_node min_node(bst_node node)
{
bst_node current = node;
//Finding the leftmost leaf 
while (current->left != NULL)
current = current->left;
return current;
}

// Function to delete the given node 
bst_node deletenode(bst_node root, int data)
{
if (root == NULL)
return root;
if (data < root->data)
root->left = deletenode(root->left, data);
else if (data > root->data)
root->right = deletenode(root->right, data);
else
{
// node with only one child or no child
if (root->left == NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
struct node *temp = root->left;
free(root);
return temp;
}
//For node with two children
bst_node temp = min_node(root->right);
// Copying the inorder successor's content to this node
root->data = temp->data;
// Deleting the inorder successor
root->right = deletenode(root->right, temp->data);
}
return root;
}

//Function that returns the maximum element
int max(int a, int b)
{
	return (a>b ?a:b);
}

//Function to calculate the height of the tree
int height(bst_node root) {
    if (root == NULL) 
        return 0;
    else {
        // Finding the height of left and right subtrees
        int left_height = height(root->left);
        int right_height = height(root->right);
         
        // Find max(subheight) + 1 to get the height of the tree
        return max(left_height, right_height) + 1;
		}
	}
void elements_in_a_level(bst_node root, int level)
 {
    if (!root)
        return;
    if (level == 0) 
	{
        // Indicates the Top of a sub tree
        printf("%d -> ", root->data);
    }
    else 
	{
        elements_in_a_level(root->left, level - 1);
        elements_in_a_level(root->right, level - 1);
    }
 
}
		
void level_order_traversal(bst_node root)
{
    int ht = height(root);
    int i=0;
	for (i=0; i<ht; i++) 
	{
        elements_in_a_level(root, i);
    }
}

int main()
{  
  int num,ch;
  bst_node root = NULL;
  while(1) 
  {
    printf("1.Insertion 2.Deletion 3.Search 4.Print 5.Exit\n"); 
    printf("Enter your option :\n");
    scanf("%d", &ch);
    switch(ch) 
	{		    	
		case 1: 
				printf("Enter an element to be inserted : \n"); 
				scanf("%d", &num);
				root = insertnode(root,num);
				break;
		case 2:
				printf("Enter an element to be deleted : \n");
				scanf("%d",&num);
				root = deletenode(root,num);
				break;	
		case 3: 
				printf("Enter an element to be searched :\n ");
				scanf("%d",&num);
				if(searchnode(root, num) == NULL)
					printf("Element not found in the binary search tree.\n");
				else
					printf("Element found in the binary search tree.\n");	
				break;	  
		case 4:
				if(root == NULL)
				printf("Binary Search Tree is empty.\n");
				else 
				{
				    printf("Elements of the BST Level Order Traversal: \n");
				    level_order_traversal(root);
				    printf("\n");
				}
				break;
		case 5:
		  		exit(0);
		default:
				printf("Invalid choice \n");
      }
  }
  
  return 0;
}

