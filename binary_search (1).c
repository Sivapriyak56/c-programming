/* Binary Search */

#include <stdio.h> 

void read(int arr[], int *limit)
{
    int i;
    printf("\nEnter number of elements:");
    scanf("%d", limit);
    
    printf("\nEnter elements in ascending order : ");
    for( i = 0; i < *limit; i++ )
        scanf("%d", &arr[i]);
    
}

int binarySearch(int arr[], int lower, int upper, int element) 
{ 
    int mid;
    
	if (upper >= lower)
	{ 
		mid = lower + (upper - lower) / 2; 

		if (arr[mid] == element) 
			return mid; 

		if (arr[mid] > element) 
			return binarySearch(arr, lower, mid - 1, element); 

		return binarySearch(arr, mid + 1, upper, element); 
	} 

	return -1; 
} 

void display(int arr[], int *limit)
{
    int i;
    
    if( *limit > 0 )
    {
        printf("\nThe array elements are: ");
        for( i = 0; i < *limit; i++ )
            printf("%d ", arr[i]);
    }
    else
        printf("\nArray is empty. Please call read option\n");
    
    
}

int main()
{
    int arr[10], element, result;
    int lowerlimit = 0, upperlimit = -1;
    int ch, e = 1;
    
    while( e )
    {
        printf("\n----------MENU----------\n");
        printf("\n\t1. Read Elements\n\t2. Binary Search\n\t3. Display\n\t4. Exit\n");
        printf("\n------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch( ch )
        {
            case 1: read(arr, &upperlimit);
                    break;
            case 2: if(upperlimit > 0)
                    {
                        printf("\nEnter the element to search:");
                        scanf("%d",&element);
                        result = binarySearch(arr, lowerlimit, upperlimit, element);
                        /* Conditional operator is also known as a ternary operator in C */
                        (result == -1) ? printf("Element is not present in the array"): printf("Element is present at the position %d",result + 1); 
                    }
                    else
                        printf("\nArray is empty. Please call read option\n");
                    break;
            case 3: display(arr, &upperlimit);
                    break;
            case 4: e = 0;
                    printf("\n Exiting from the program\n");
                    break;
            default: printf("\nPlease enter valid choice\n");
        }
    }
    
    
    return 0;
    
}

