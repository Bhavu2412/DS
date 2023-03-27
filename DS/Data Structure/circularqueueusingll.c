#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
struct node *createnode(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head;
    return temp;
}
void createll(){
    struct node *new,*temp;
    int ans=1;
    while(ans==1){
            new=createnode();
            printf("Enter the value of node :\n");
            scanf("%d",&new->data);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
        printf("Enter 1 to add new node :\n");
        scanf("%d",&ans);
    }
}
void display(){
    struct node *p=head;
   do{
        printf("DATA :%d\n",p->data);
        p=p->next;
    } while(p->next!=head);
}
void enqueue(){
    struct node *p=head,*new;
    new=createnode();
    printf("Enter the value :\n");
    scanf("%d",&new->data);
   do{
     p=p->next;
    }while(p->next!=head);
    p->next=new;
    new->next=head;
}

void dequeue(){
    struct node *p;
    p=head;
    do{
     p=p->next;
    }while(p->next!=head);
    free(head);
    head=head->next;
    p->next=head;
    
}
int main(){
    createll();
//  int a=1,op;
//    while(a==1){
//        printf("1 for enqueue\n2 for dequeue\n3 for display\nEnter :");
//        scanf("%d",&op);
//        switch(op){
//         case 1:
//         enqueue();
//         break;
//         case 2:
        dequeue();
//         break;
//         case 3:
         display();
//         break;
//         default :
//         printf("This cannot be performed.\n");
//         }
//        printf("Enter 1 to perform other operation :\n");
//        scanf("%d",&a);
//    }
}