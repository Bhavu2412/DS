#include<stdio.h>
const max = 10;
int arr[max];
int f=0,r=-1;

void enqueue(){
    if(r!=max-1){
        int val;
        printf("Enter the value to be added :");
        scanf("%d",&val);
        r=r+1;
        arr[r]=val;
    }
    else{
        printf("Queue overflow.\n");
    }
}
void dequeue(){
    if(r==f-1){
        printf("Queue underflow.\n");
    }
    else{
        f=f+1;
    }
}
void display(){
    int i;
    if(r==f-1 || r==-1){
        printf("Queue is empty.");
    }
    else{
        for(i=f;i<=r;i++){
        printf("DATA :%d",arr[i]);
        }
    }
    

}
int main(){
    int ans=1,op;
    while(ans==1){
        printf("1 for enqueue.\n2 for dequeue.\n3 for display.\nEnter :");
        scanf("%d",&op);
        switch(op){
            case 1 :
            enqueue();
            break;
            case 2 :
            dequeue();
            break;
            case 3 :
            display();
            break;
            default :
            printf("Operation cannot be performed.");
            break;
        }
        printf("\nEnter 1 to perform operation :");
        scanf("%d",&ans);
    }
}
