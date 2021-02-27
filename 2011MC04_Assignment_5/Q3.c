//Avinash Singh 2011MC04
//AVL Tree
#include<stdio.h>
#include<stdlib.h>

//Defining structure of a Node
struct node { 
  int data; 
  struct node *left, *right;
  int n_height;
} ;

//Type Definition , so that we can use bst_node to represent a node pointer.
typedef struct node *bst_node;

//Function to create the first nide in the Tree
bst_node newnode(int item) 
{
  bst_node temp = (bst_node)malloc(sizeof(struct node)); 
  temp->data = item;
  temp->left = temp->right = NULL;
  temp->n_height = 1;
  return temp;
}

// A function to get the height of the tree
int height1(bst_node N)
{
	if (N == NULL)
		return 0;
	return N->n_height;
}


// Function to right rotate subtree with root y
bst_node rotate_right(bst_node y)
{
	bst_node x = y->left;
	bst_node T2 = x->right;

	// rotation
	x->right = y;
	y->left = T2;

	// Updating heights
	y->n_height = max(height1(y->left), height1(y->right))+1;
	x->n_height = max(height1(x->left), height1(x->right))+1;

	// Returning new root
	return x;
}


// A  function to   left rotate subtree with root  x
bst_node rotate_left(bst_node x)
{
	bst_node y = x->right;
	bst_node T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->n_height = max(height1(x->left), height1(x->right))+1;
	y->n_height = max(height1(y->left), height1(y->right))+1;

	// Return new root
	return y;
}

//Balance factor of node N
int balance_factor(bst_node N)
{
	if (N == NULL)
		return 0;
	return height1(N->left) - height1(N->right);
}

//Function to insert nodes in a Tree
bst_node insertnode(bst_node node, int ele) 
{
  if(node == NULL){
    printf("Successfully inserted,\n");
    return newnode(ele);
  }
  else{    //We will do insertion such that it satisfies the property of an AVL Tree 
    if(ele <= node->data){
     node->left = insertnode(node->left, ele);
    }
    else if(ele > node->data){
     node->right = insertnode(node->right, ele);
    } 
    else
    {
		printf("Element already exists in BST");
		return node;
	}
	
	node->n_height = 1 + max(height1(node->left),height1(node->right));


	int balance = balance_factor(node);

	// LL
	if (balance > 1 && ele < node->left->data)
		return rotate_right(node);

	// RR
	if (balance < -1 && ele > node->right->data)
		return rotate_left(node);

	// LR
	if (balance > 1 && ele > node->left->data)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	// RL 
	if (balance < -1 && ele < node->right->data)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	
	return node;
}

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
bst_node deletenode(bst_node root, int ele) 
{ 
    
    if (root == NULL) 
        return root; 
    if ( ele < root->data ) 
        root->left = deletenode(root->left, ele); 
    else if( ele > root->data ) 
        root->right = deletenode(root->right, ele); 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            bst_node temp = root->left ? root->left : root->right; 
            //If no child  
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
			// If One child  
             *root = *temp;   
            free(temp); 
        } 
        else
        { 
            // For node with two children: successor is  (smallest in the right subtree) 
            bst_node temp = min_node(root->right); 
            root->data = temp->data; 
            // Deleting the inorder successor 
            root->right = deletenode(root->right, temp->data); 
        } 
    } 
    
     // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
	   
    root->n_height = 1 + max(height1(root->left),height1(root->right)); 
                           
    int balance = balance_factor(root);

	// LL
	if (balance > 1 && ele < root->left->data)
		return rotate_right(root);

	// RR
	if (balance < -1 && ele > root->right->data)
		return rotate_left(root);

	// LR
	if (balance > 1 && ele > root->left->data)
	{
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}

	// RL 
	if (balance < -1 && ele < root->right->data)
	{
		root->right = rotate_right(root->right);
		return rotate_left(root);
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
         
        // Finding max(subheight) + 1 to get the height of the tree
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

