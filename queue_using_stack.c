/* Queue using Stacks */
#include <stdio.h>

void push(int stack[],int *top, int ele)
{
    *top = *top + 1;
    stack[*top] = ele;
}
 
int pop(int stack[], int *top)
{
    int ele;
    ele = stack[*top];
    *top = *top - 1;
    return(ele);
}
 
void enqueue(int stack1[], int *top1)
{
    int i, ele;
 
    printf("Enter the element:");
    scanf("%d", &ele);
    push(stack1, top1, ele);
}
 
void dequeue(int stack1[], int *top1, int stack2[], int *top2)
{
    int i;
    int count = *top1;
    for (i = 0;i <= count;i++)
    {
        push(stack2,top2,pop(stack1,top1));
    }
    printf("\nThe element %d is deleted from queue\n", pop(stack2,top2));
    
    count = *top2;
    for (i = 0;i <= count;i++)
    {
        push(stack1,top1,pop(stack2,top2));
    }
}
 
/* Display the elements in the stack1*/
 
void display(int stack[], int *top)
{
    int i;
 
    for (i = 0;i <= *top; i++)
    {
        printf(" %d ", stack[i]);
    }
}

void main()
{
   int stack1[20], stack2[20];
   int top1 = -1, top2 = -1;
   int ch;
   int e = 1;
   
   printf("\nQUEUE using STACKS\n");
   while( e )
   {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: enqueue(stack1, &top1);
                    break;
            case 2: dequeue(stack1,&top1,stack2,&top2);
                    break;
            case 3: display(stack1,&top1);
                    break;
            case 4: e = 0;
                    printf("\nExiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
}