//binary search algo
#include<stdio.h>
void binarysearch(int arr[],int l,int n,int s){
    int mid=l+(n-l)/2;
    if(arr[mid]==s){
        printf("Found at %d",mid);
    }
    else if(arr[mid]>s){
        binarysearch(arr,l,mid-1,s);
    }
    else{
        binarysearch(arr,mid+1,n,s);
    }
}

    int main ()
{
 int i,n,arr[10],s;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&n);
 printf ("Enter the numbers : \n");
 for (i=0;i<n;i++)
  scanf("%d",&arr[i]);
printf ("\nEnter the number to be search : ");
 scanf ("%d",&s);
 binarysearch(arr,0,n-1,s);

}
