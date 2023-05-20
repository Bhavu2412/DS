//quicksort
#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int l,int h){
    int pivot=arr[h];
    int j=l-1;
    for(int i=l;i<h;i++){
        if(arr[i]<=pivot){
            j++;
            swap(&arr[i],&arr[j]);
        }
    }
           swap(&arr[j+1],&arr[h]);
    return (j+1);
}
void quicksort(int arr[],int l,int h){
    if(l<h){
        int mid=partition(arr,l,h);
        quicksort(arr,l,mid-1);
        quicksort(arr,mid+1,h);
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
    quicksort(arr,0,n-1);
    end=clock();
    double duration=((double)end-start);
    printf("The time taken is %f\n",duration);
    printf("The array is :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}