#include<stdio.h>
void hash(int arr[],int i,int k,int n){
    int j=(k%n+i)%n;
    if(i>n){
        printf("Sorry i cant do any thing :(");
    }
    else if(arr[j]==-1){
        arr[j]=k;
    }
    else if(arr[j]!=-1){
        hash(arr,i+1,k,n);
    }
    else{
        printf("Cannot be done.");
    }
}
int main(){
    int arr[10],i,j,k,n,c=1;
    printf("Enter the size of hash table :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=-1;
    }
    while(c==1){
        printf("Enter the key :");
        scanf("%d",&k);
        hash(arr,k,0,n);
        printf("Enter 1 :");
        scanf("%d",&c);
    }
    for(int i=0;i<n;i++){
    if(arr[i]!=-1){
        printf("|%d",arr[i]);
        }
    else{
        printf("|NULL");
    }
    }
    printf("|");
}