#include<stdio.h>
int getminm(int a[],int low,int high){

    int size=high-low+1;
    if(size==1){
        return(a[low]);
    }
    else if(size==2){
        return(a[high]>a[low]?a[low]:a[high]);
    }
    else{
        int mid=((low+high)/2);

        return getminm(a,low,mid-1)>getminm(a,mid+1,high)?getminm(a,mid+1,high):getminm(a,low,mid-1);

    }
}

int getmaxm(int a[], int low,int high){
    int size=high-low+1;
    if(size==1){
        return(a[low]);
    }
    else if(size==2){
        return(a[high]>a[low]?a[high]:a[low]);
    }
    else{
        int mid=((low+high)/2);
        return getmaxm(a,low,mid-1)>getmaxm(a,mid+1,high)?getmaxm(a,low,mid-1):getmaxm(a,mid+1,high);
    }
}
void main(){

    int a[]={2,41,8,99,36};
    int min=getminm(a,0,4);
    printf("Min is : %d\n",min);
    int max=getmaxm(a,0,4);
    printf("Max is : %d\n",max);

}
