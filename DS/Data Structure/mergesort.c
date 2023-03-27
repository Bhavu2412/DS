#include<stdio.h>
void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;//
    int n2=r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];

    }
    for(int j=0;j<n2;j++){
        R[j]=arr[q+1+j];
    }
    int i,j,k;
    i=0;
    j=0;
    k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("DATA :%d\n",arr[i]);
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int arr[]={1,5,3,8,2,6,4,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    display(arr,n);
}