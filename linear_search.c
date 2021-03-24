#include<stdio.h>

void Read(int a[], int *n)
{
    int i;
    printf("\nEnter number of elements:");
    scanf("%d", n);
    
    printf("\nEnter elements: ");
    for( i = 0; i < *n; i++)
        scanf("%d", &a[i]);
    
    
}

void Search( int a[], int *n)
{
    int e,i;
    printf("\nEnter element to search:");
    scanf("%d", &e);
    
    for( i = 0; i < *n; i++)
        if(a[i] == e)
        {
            printf("\nThe element %d found at %d location", e, i+1);
            return;
        }
            
            
    printf("\nThe element %d is not present in the array",e);
    
}

void display(int a[], int *n)
{
    int i;
    
    printf("\nThe stack elements are:");
    for( i = 0; i < *n; i++ )
        printf("%d ", a[i]);
    
}

int main()
{
    int arr[10], n = 0;
    int ch, e = 1;
    
    while( e )
    {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Read\n\t2. Search\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: Read(arr, &n);
                    break;
            case 2: Search(arr,&n);
                    break;
            case 3: display(arr, &n);
                    break;
            case 4: e = 0;
                    printf("\n Exiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
    
    
    return 0;
    
}
