#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(a[min_ind]>a[j])
            min_ind=j;
        }
        swap(&a[i],&a[min_ind]);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
        }
}
int main(){
    int arr[]={5,2,4,1,3,0};
    int n=sizeof(arr)/sizeof arr[0];
     selectsort(arr,n);
     display(arr,n);
}