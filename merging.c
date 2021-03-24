  #include <stdio.h>

void read(int arr[], int *limit)
{
    int i;
    printf("\nEnter the limit:");
    scanf("%d",limit);
    printf("\nEnter elements in ascending order:");
    for( i = 0; i < *limit; i++)
        scanf("%d",&arr[i]);
}

int merge(int arr1[], int limit1, int arr2[], int limit2, int result[], int resultlimit)
{
    int i;
    int i1 , i2 ;
    i1 = i2 = 0;
    
    for( i = 0; i < resultlimit; i++ )
    {
        
        if(i1 >= limit1 || i2 >= limit2)
        {
            break;
        }

        if(arr1[i1] < arr2[i2])
        {
            result[i] = arr1[i1];
            i1++;
        }
        else
        {
            result[i] = arr2[i2];
            i2++;
        }
    }

    while(i1 < limit1)
    {
        result[i] = arr1[i1];
        i++;
        i1++;
    }
    while(i2 < limit2)
    {
        result[i] = arr2[i2];
        i++;
        i2++;
    }

}
 
void display(int arr1[], int limit1, int arr2[], int limit2, int result[], int resultlimit, int flag)
{
    int i;
    if( limit1 <= 0 || limit2 <= 0)
    {
        printf("\nEmpty arrays. Choose read option");
        return;
    }
    else
    {
        printf("\nFirst array elements are: ");
        for( i = 0; i < limit1; i++)
            printf("%d\t", arr1[i]);
        printf("\nSecond array elements are: ");
        for( i = 0; i < limit1; i++)
            printf("%d\t", arr2[i]);
        if(flag)
        {
            printf("\nMerged array is: ");
            for(i=0; i<resultlimit; i++)
            {
                printf("%d\t", result[i]);
            }
        }
    }
} 

void main()
{
   int arr1[20], arr2[20], result[40];
   int limit1, limit2, resultlimit;
   int flag = 0;
   int ch;
   int e = 1;
   
   printf("\nMerging two sorted arrays\n");
   while( e )
   {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Read arrays\n\t2. Merge\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: printf("\nRead first array\n");
                    read(arr1, &limit1); 
                    printf("\nRead second array\n");
                    read(arr2, &limit2);
                    break;
            case 2: if( limit1 <= 0 || limit2 <= 0)
                    {
                        printf("\nEmpty arrays. Choose read option");
                    }
                    else
                    {
                        resultlimit = limit1 + limit2;
                        merge(arr1, limit1, arr2, limit2, result, resultlimit);
                        flag = 1;
                    }
                    break;
            case 3: display(arr1, limit1, arr2, limit2, result, resultlimit, flag);
                    break;
            case 4: e = 0;
                    printf("\nExiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
}
