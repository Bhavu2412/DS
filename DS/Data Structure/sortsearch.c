#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int min(int *x,int *y){
    return (x<=y)? x:y;
}
int fibosearch(int arr[],int s,int n){
    int t1=0,t2=1,ntm=t1+t2;
    while(ntm<n){
        t1=t2;
        t2=ntm;
        ntm=t1+t2;
    }
    int offset=-1;
    while(ntm>1){
        int i=min(offset+t1,n-1);
        if(arr[i]<s){
            ntm=t2;
            t2=t1;
            t1=ntm-t2;
            offset=i;
        }
        else if(arr[i]>s){
            ntm=t1;
            t2=t2-t1;
            t1=ntm-t2;
        }
        else{
            return i;
        }
        
    }
         if(t2 && arr[offset+1]==s)
            return offset+1;

            return -1;
}
void insertionsort(int arr[],int n){
    int j,i,key;
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
void bubblesort(int arr[],int n){
    int i,j,temp=0;
    for(i=0;i<n-1;i++){
    
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
               swap(&arr[j],&arr[j+1]);
            }
            
        }
    }
}
void selectionsort(int arr[],int n){
    
    int min_ind,i,j;
    for(i=0;i<n-1;i++){
        min_ind=i;
       for(j=i;j<n;j++){
           if(arr[j]<arr[min_ind])
               min_ind=j;
       }
           if(min_ind!=i)
               swap(&arr[min_ind],&arr[i]);   
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[high],j=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<arr[pivot]){
            j++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[high],&arr[j+1]);
    return j+1;

}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int d=partition(arr,low,high);
        quicksort(arr,low,d-1);
        quicksort(arr,d+1,high);
    }
}
void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("Data :%d\n",arr[i]);
    }
}
int binarysearch(int arr[],int n,int s){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==s){
            return mid;

        }
        else if(arr[mid]>s){
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[10],n,i,num;
    printf("Enter the number of element :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the value of :");
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched :");
    scanf("%d",&num);
    int gi=fibosearch(arr,num,n);
    printf("%d",gi);
    //bubblesort(arr,n);
    //selectionsort(arr,n);
    //insertionsort(arr,n);
    //quicksort(arr,0,n-1);
                //binary search
    // int a=binarysearch(arr,n,num);
    // if(a!=-1){
    //     printf("Found at index %d",a);
    // }
    // else{
    //     printf("Not found.");
    // }
                //
    //display(arr,n);
}