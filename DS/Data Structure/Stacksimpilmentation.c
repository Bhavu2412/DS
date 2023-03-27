#include<stdio.h>
#define max 10
int arr[max],top=-1;
void pop(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        top=top-1;
    }
}
void push(){
    int val;
    top=top+1;
    printf("Enter the value :");
    scanf("%d",&val);
    arr[top]=val;
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("|DATA :%d\t|\n",arr[i]);
    }
}
int main(){
    int op,ans=1;
    while(ans==1){
        printf("Enter 1 to push 2 to pop 3 to display.\n");
        scanf("%d",&op);
        switch(op){
            case 1 :
            push();
            break;
            case 2 :
            pop();
            break;
            case 3 :
            display();
            break;
            default :
            printf("No operation can be performed.");
        }
        printf("Enter 1 to perform operation :");
        scanf("%d",&ans);
    }
}