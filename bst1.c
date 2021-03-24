
#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *left, *right;
};

typedef struct node node;

node *newnode(int item)
{
    node *temp = (node *)malloc( sizeof( node ) );
    temp -> data = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

node *Insert(node *root, int ele) 
{
    if( root == NULL)
        return newnode( ele );

    if( ele < root -> data)
        root -> left = Insert( root -> left, ele);
    else
        root -> right = Insert( root -> right, ele);

    return root;
}

node *Create( node *root )
{
    int num, i, ele;
    printf("\n Enter number of nodes:");
    scanf("%d", &num );
    printf("\n Enter elements:");
    for( i = 0; i < num; i++)
    {
        scanf("%d", &ele);
        root = Insert( root, ele);
    }
    
    return root;
}


void Inorder( node *root )
{
  if (root != NULL)
  {
      Inorder( root -> left );
      printf("%d -> ", root -> data );
      Inorder( root -> right );
  }
}

node *minvalnode( node *p )
{
    node *current;
    current = p;
    while( current && current -> left != NULL)
        current = current -> left;
    return current;
}

node *Delete( node *root, int ele )
{
    if( root == NULL)
        return root;

    if ( ele < root -> data )
        root -> left = Delete( root -> left, ele );
    else if( ele > root -> data )
    root -> right = Delete( root -> right, ele );
    else
    {
        if( root -> left == NULL )
        {
            node *temp = root -> right;
            free( root );
            return temp;
        }
        else if( root -> right == NULL )
        {
            node *temp = root -> left;
            free( root );
            return temp;
        }
        node *temp = minvalnode( root -> right );
        root -> data = temp -> data;
        root -> right = Delete( root -> right, temp -> data );
  }
  return root;
}



int main()
{
	
	node *root = NULL;
	int ele;
	int e = 1, ch;
	
	while( e ) 
	{
		printf( "\n--------------MENU--------------\n" );
		printf( "\n\t1. Create\n\t2. Insert\n\t3. Inorder Traversal\n\t4. Delete\n\t5. Exit\n" );
		printf( "\n--------------------------------\n" );
		printf( "\n Enter your choice:" );
		scanf( "%d", &ch );
		
		switch( ch )
		{
			case 1: root = Create( root );
			     break;
			case 2: 
			        printf("\n Enter the element to insert:");
			        scanf("%d", &ele);
			        root = Insert( root, ele);
				 break;
			case 3: Inorder( root );
				 break;
			case 4: 
			        printf("\n Enter the element to delete :");
			        scanf("%d", &ele);
			        root = Delete( root, ele );
				 break;
		    case 5: e = 0;
				 break;
			default: printf( "\n Invalid choice \n" );
		}
		
	}
	return 0;
} 


