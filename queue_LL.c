#include<stdio.h>   
#include<stdlib.h>  
struct Node   
{  
    int data;   
    struct Node *next;  
};  
struct Node *front = NULL;  
struct Node *rear = NULL;   

void insert()  
{  
    struct Node *temp;  
    int val;   
      
    temp = (struct Node *) malloc (sizeof(struct Node));  
    
    if(temp == NULL)  
    {  
        printf("\nQUEUE overflow\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value:");  
        scanf("%d",&val);  
        
        temp -> data = val;  
        temp -> next = NULL;
        
        if(front == NULL)  
        {  
            front = rear = temp;  
        }  
        else   
        {  
            rear -> next = temp;  
            rear = temp;  
        }  
        printf("\nOne value inserted into the QUEUE\n");
    }  
}     

void delete ()  
{  
    struct Node *temp;  
    if(front == NULL)  
    {  
        printf("\nQUEUE underflow\n");  
        return;  
    }  
    else   
    {  
        temp = front;  
        front = front -> next;  
        printf("\nThe value %d is deleted from QUEUE", temp->data);
        free(temp);  
    }  
}  


void display()  
{  
    struct Node *temp;  
    temp = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nQUEUE elements are:");  
        while(temp != NULL)   
        {  
            printf("%d ", temp -> data);  
            temp = temp -> next;  
        }  
    }  
}  

void main()
{
   int ch;
   int e = 1;
   
   printf("\nQUEUE using Linked List\n");
    while( e )
    {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: e = 0;
                    printf("\nExiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
}
  
