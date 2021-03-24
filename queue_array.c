#include<stdio.h>

void Insert(int a[], int *front, int *rear)
{
    int e;
    printf("\nEnter number:");
    scanf("%d", &e);
    
    if( (*front == -1) && (*rear == -1) )
        {   
            *front = *rear = 0;
        }
    else
        {
            *rear += 1;
        }
        
    a[*rear] = e;
    printf("\nThe entered element %d is inserted in to the QUEUE\n",e);
}

void Delete(int a[], int *front, int *rear)
{
    int e;
    
    e = a[*front];
    printf("\nThe element %d deleted from QUEUE",e);
    *front += 1;
   
}

void display(int a[], int *front, int *rear)
{
    int i;
    
    printf("\nThe QUEUE elements are:");
    for( i = *front; i <= *rear; i++ )
        printf("%d ", a[i]);
    
}

int main()
{
    int arr[10];
    int front, rear;
    int ch, e = 1;
    
    front = rear = -1;
    
    while( e )
    {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: Insert(arr, &front, &rear);
                    break;
            case 2: Delete(arr,&front, &rear);
                    break;
            case 3: display(arr, &front, &rear);
                    break;
            case 4: e = 0;
                    printf("\n Exiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
    
    
    return 0;
    
}
