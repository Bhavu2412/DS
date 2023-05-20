//mergesort
#include<stdio.h>
#include<time.h>
void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],M[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++){
        M[j]=arr[q+j+1];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[j];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=M[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int p,int r){
    if(p<r){
        int m = p + (r - p) / 2;
        mergesort(arr,p,m);
        mergesort(arr,m+1,r);
        merge(arr,p,m,r);
    }
}
int main(){
    clock_t start,end;
    int arr[10],n;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the value of :");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",i+1);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    start=clock();
    mergesort(arr,0,n);
    end=clock();
    double duration=((double)end-start);
    printf("The time taken is %f\n",duration);
    printf("The array is :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}