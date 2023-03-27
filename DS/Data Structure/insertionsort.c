#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void insertionsort(int arr[],int n){
    int i;
    for(i=0;i<n-1;i++){
       if(arr[i]>arr[i+1]){
           swap(&arr[i],&arr[i+1]);
           while(i!=0){
               if(arr[i]<arr[i-1]){
                   swap(&arr[i],&arr[i-1]);
               }
               i--;
           }
       }
    }
}
void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}
int main(){
    int arr[10]={12,11,13,5,6,23,54,22,76,34};
    insertionsort(arr,10);
    display(arr,10);
}