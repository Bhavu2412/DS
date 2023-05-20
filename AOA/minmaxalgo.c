//minmaxc algo
#include<stdio.h>
int arr[100];
int min,max;
void minmax(int l,int h){
    int max1,min1;
    if(l==h){
        min=arr[l];
        max=arr[l];
    }
    else {
        if(l==h-1){
        if(arr[l]<arr[h]){
        min=arr[l];
        max=arr[h];
        }
        else{
        min=arr[h];
        max=arr[l]; 
        }
    }
    else{
        int mid=(h+l)/2;
        minmax(l,mid);
        max1 = max; 
        min1 = min;
        minmax(mid+1,h);
        if(max<max1)
        max=max1;
        if(min>min1)
        min=min1;
    }
    }
}
int main ()
{
 int i,n;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&n);
 printf ("Enter the numbers : \n");
 for (i=1;i<=n;i++)
  scanf("%d",&arr[i]);

minmax(1,n);
printf("The max and min is :%d %d",max,min);
 return 0;
}