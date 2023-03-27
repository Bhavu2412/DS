#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
struct node *createnode(){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->next=NULL;
    return new;
}
void push(){
    struct node *new=createnode(),*temp;
    printf("Enter the data of new node :");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    
}
void pop(){
   if(head!=NULL){
        struct node *temp=head;
    head=head->next;
    free(temp);
    }
    else{
        printf("No stack found.");
    }
}
void enqueue(){
    struct node *new=createnode(),*p=head;
    printf("Enter the data of new node :");
    scanf("%d",&new->data);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new;
    new->next=NULL;
}
void dequeue(){
    if(head!=NULL){
        struct node *temp=head;
    head=head->next;
    free(temp);
    }
    else{
        printf("Queue underflow.");
    }

}
void createll(){
    int ans=1;
    struct node *temp,*new;
    while(ans==1){
        new=createnode();
        printf("Enter the data of new node :");
        scanf("%d",&new->data);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
        printf("Enter 1 to add node :");
        scanf("%d",&ans);
    }
}
void display(){
    struct node *p=head;
    while(p!=NULL){
        printf("Data :%d\t",p->data);
        p=p->next;
    }
}
int main(){
    int op,ans=1,ope;
    createll();
    printf("Enter 1 for stacks and 2 for queue :");
    scanf("%d",&ope);
    switch(ope){
        case 1:
            while(ans==1){
            printf("Enter number :");
            scanf("%d",&op);
            switch(op){
                case 1:
                push();
                break;
                case 2:
                pop();
                break;
                case 3:
                display();
                break;
                default:
                printf("Operation cannot be performed.");
                printf("Enter 1 perfrom more operation :");
                scanf("%d",&ans);
            }
        }
        break;
        case 2:
            while(ans==1){
            printf("Enter number :");
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
                default:
                printf("Operation cannot be performed.");
                printf("Enter 1 perfrom more operation :");
                scanf("%d",&ans);
            }
        }
        break;
        default:
        printf("Operation cannot be performed.");
    }

    
}