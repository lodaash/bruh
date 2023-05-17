#include <stdio.h>

int amt;
    void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
     
    // A function to implement bubble sort
    void sort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
     
            // Last i elements are already in place
            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }

void container(int C[], int n)
{

    int i;

    sort(C, n);

    printf("The order of the containers is ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t",C[i]);
    }

    int loaded = 0;
    int j = 0;

    while (C[j] <= amt)
    {
        loaded++;
        amt -= C[j];
        j++;
    }

    printf("\n The number of containers that can be loaded is : %d", loaded);
}

int main()
{

    int n, i, j;
    int C[100];

    printf( "Enter the number of containers :");
    scanf("%d",&n);

    printf( "Enter the weight of the containers :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&C[i]);
    }

    printf("Enter the limit  of containers :\n");
    scanf("%d",&amt);

    container(C, n);
    return 0;
}

