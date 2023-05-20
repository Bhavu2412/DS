//selectionsort
#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_ind=i;
        for(int j=i;j<n;j++){
            if(arr[min_ind]>arr[j]){
                swap(&arr[j],&arr[i]);
            }
        }
    }
}
int main(){
    int arr[1000000],n;
    clock_t start,end;
    // printf("Enter the number of elements :");
    // scanf("%d",&n);
    //printf("Enter the value of :");
    //printf("\n");
    for(int i=0;i<1000000;i++){
        arr[i]=i;
        //printf("%d ",i+1);
        //scanf("%d",&arr[i]);
        //printf("\n");
    }
    start=clock();
    selectionsort(arr,n);
    end=clock();
    double duration=((double)end-start);
    printf("Time taken is :%f",duration);
    // printf("The array is :\n");
    // for(int i=0;i<n;i++){
    //     printf("%d\t",arr[i]);
    // }
    return 0;
}