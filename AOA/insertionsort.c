//insertionsort
#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
            while(i>0){
                if(arr[i]<arr[i-1]){
                    swap(&arr[i],&arr[i-1]);
                }
                i--;
            }
        }  
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
    insertionsort(arr,n);
    end=clock();
    double duration=((double)end-start);
    printf("The time taken is %f",duration);
    // printf("The array is :\n");
    // for(int i=0;i<n;i++){
    //     printf("%d\t",arr[i]);
    // }
    return 0;
}