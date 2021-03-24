#include<stdio.h>

void push(int a[], int *top)
{
    int e;
    printf("\nEnter number:");
    scanf("%d", &e);
    
    *top = *top + 1;
    a[*top] = e;
    printf("\nThe entered element %d pushed in to the stack...\n",e);
}

void pop( int a[], int *top)
{
    int e;
    
    e = a[*top];
    printf("\nThe element %d poped from STACK",e);
    *top = *top - 1;
   
}

void display(int a[], int *top)
{
    int i;
    
    printf("\nThe stack elements are:");
    for( i = *top; i >= 0; i-- )
        printf("%d ", a[i]);
    
}

int main()
{
    int arr[10], top = -1;
    int ch, e = 1;
    
    while( e )
    {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: push(arr, &top);
                    break;
            case 2: pop(arr,&top);
                    break;
            case 3: display(arr, &top);
                    break;
            case 4: e = 0;
                    printf("\n Exiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
    
    
    return 0;
    
}
