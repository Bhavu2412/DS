#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head;
struct node *createnode(){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
};
void addatindex(){
    struct node *p=head,*q=head->next,*new;
    new=createnode();
    int i=1,index;
    printf("Enter the index:\n");
    scanf("%d",&index);
    printf("Enter the data of new node :");
    scanf("%d\n",&new->data);
    while(index>i){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=new;
    new->next=q;                      
}
void reverselist(){
    struct node *curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void deleteatstart(){
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
}
void deleteatend(){
    struct node *p=head,*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);

}
void deleteatindex(){
    struct node *p=head,*q=head->next;
    int i=2,index;
    printf("Enter the index:\n");
    scanf("%d",&index);
    while(i!=index){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
}
void deletewithvalue(){
    struct node *p=head,*q=head->next;
    int i=1,v;
    printf("Enter the index:\n");
    scanf("%d",&v);
    
    while(q->data!=v){
        p=p->next;
        q=q->next;
        if(q->next==NULL){
            printf("The value is not found.\n");
        }
        i++;
    }
    p->next=q->next;
    free(q);
}
void addatstart(){
    struct node *new;
    new=createnode();
    printf("Enter the data of new node :");
    scanf("%d\n",&new->data);
    new->next=head;
    head=new;
    
}
void addatend(){
    struct node *new,*p=head;
    new=createnode();
    printf("Enter the data of new node :");
    scanf("%d\n",&new->data);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new;
    new->next=NULL;  
}

void display(){
    struct node *p=head;
    if(head!=NULL){
        while(p->next!=NULL){
            printf("Data :%d\n",p->data);
            p=p->next;
        }
    }
    else{
        printf("LL not found.\n");
    }
}
void createll(){
    struct node *new,*temp;
    temp=head;
    int ans=1;
    while(ans==1){
    new=createnode();
    printf("Enter the value :\n");
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
int main(){
    int p,o;
    createll();
    // printf("Enter 1 to add\t Enter 2 to delete\n Enter :");
    // scanf("%d",&o);
    // switch(o){
    //     case 1 :
    //         printf("Enter 1 to add at start.\t2 to add at end.\t3 to add at index.\n Enter :");
    //         scanf("%d",&p);
    //         switch(p){
    //         case 1:
    //             addatstart();
    //         break;
    //         case 2:
    //             addatend();
    //         break;
    //         case 3:
    //             addatindex();
    //         break;
    //         default :
    //         printf("Cannot do the operation try again.\n");   
    //         }
    //         display();
    //     break;
    //     case 2:
    //         printf("Enter 1 to delete at start.\t2 to delete at end.\t3 to delete at index.\n 4 to delete a value.\tEnter :");
    //         scanf("%d",&p);
    //         switch(p){
    //         case 1:
    //             deleteatstart();
    //         break;
    //         case 2:
    //             deleteatend();
    //         break;
    //         case 3:
    //             deleteatindex();
    //         break;
    //         case 4:
    //             deletewithvalue();
    //         break;
    //         default :
    //         printf("Cannot do the operation try again.\n");   
    //         }
    //         display();
    //     break;
    // }
    reverselist();
    display();
}