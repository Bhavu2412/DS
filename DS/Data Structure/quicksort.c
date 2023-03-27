#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot = arr[high],j=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<=arr[high]){
            j++;
            swap(&arr[j],&arr[i]);
        }
    }
        swap(&arr[j+1],&arr[high]);
    return j+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int d=partition(arr,low,high);
         quicksort(arr, low, d - 1);
         quicksort(arr, d + 1, high);
        }
    
}
void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
int main(){
    int arr[]={1,4,2,6,5,4,8,6,5,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    display(arr,n);
}