#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
struct node *createnode(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
};
void enqueue(){
    struct node *new,*rear;
    int ans=1;
    while(ans==1)
    {
            new = createnode();
        printf("Enter the value :");
        scanf("%d",&new->data);
        if(front==NULL && rear==NULL){
            front=new;
            rear=new;
        }
        else{
            rear->next=new;
            rear=new;
        }
        printf("Enter 1 to add node :\n");
        scanf("%d",&ans);
    }
}

void dequeue(){
    struct node *temp=front;
    if(front==NULL){
        printf("Queue underflow.\n");
    }
    else{
        front=front->next; 
        free(temp);
        }
}
void display(){
    struct node *p=front;
    if(front!=NULL){
        while(p!=NULL){
            printf("Data :%d\n",p->data);
            p=p->next;
        }
    }
    else{
        printf("Queue not found.\n");
    }
}
int main(){
   int a=1,op;
   while(a==1){
       printf("1 for enqueue\n2 for dequeue\n3 for display\nEnter :");
       scanf("%d",&op);
       switch(op){
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default :
        printf("This cannot be performed.\n");
        }
       printf("Enter 1 to perform other operation :\n");
       scanf("%d",&a);
   }

}