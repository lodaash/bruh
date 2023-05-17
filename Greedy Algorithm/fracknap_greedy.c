#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

struct item{
    int index;
    int profit;
    int weight;
    float ppw;
    float used;
};

void main(){
    int n,max;
    struct item temp;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter maximum capacity: ");
    scanf("%d",&max);

    struct item arr[n];

    for(int i=0;i<n;i++){

        arr[i].index=i+1;
        printf("Enter weight and profit for each item: ");
        scanf("%d %d",&arr[i].weight,&arr[i].profit);

        arr[i].ppw=arr[i].profit/(arr[i].weight*1.0);


    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(arr[j].ppw<arr[j+1].ppw){

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The index in terms of execution is : ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i].index);
    }
    printf("\n");

    int w=max;
    float profit=0;

    for(int i=0;i<n;i++){
        if(w<=0)  //Check if the knapsack is full
        break;
        if(arr[i].weight<w){
            arr[i].used=1;
        }
        else{
            arr[i].used=w/(arr[i].weight*1.0);
        }

        profit=profit+arr[i].used*arr[i].profit;
        w=w-arr[i].weight;  //remaining weight
    }

        printf("Total profit is: %f",profit);
        
        printf("\n");
        
        printf("The vector required is: ");
        for(int i=0;i<n;i++){
            printf("%f ",arr[i].used);
        }

}
