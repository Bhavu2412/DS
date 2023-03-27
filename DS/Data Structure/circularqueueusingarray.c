#include<stdio.h>
const max = 10;
int arr[max];
int f=-1,r=-1;

void enqueue(){
    int item;
    printf("Enter the value :");
    scanf("%d",&item);
    if(f == -1 && r==-1){
            f = 0;
            r = 0;
        }
    
     else if((r+1)%max==f){
                printf("Queue Overflow");
        }
    else{
            r = (r+1)%max;
        }
        arr[r] = item ;
    
}
void dequeue(){
    if(r==f-1){
        printf("Queue underflow.\n");
    }
    else if(f==r){
        printf("The deleted element is ;%d",arr[f]);
        f=-1;
        r=-1;
    }
    else{
        f=(f+1)%max;
    }
}
void display(){
    if(f==-1 || r==-1){
        printf("Queue is empty.");
    }
    else{
        while(f!=r+1){
        printf("DATA :%d",arr[f]);
        f=(f+1)%max;
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
