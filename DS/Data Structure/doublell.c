#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next,*prev;
};
struct node *head;
struct node *createnode(){
    struct node *new=(struct node *)malloc(sizeof(struct node ));
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void addatstart(){
    struct node *new;
    new=createnode();
    printf("Enter the value :");
    scanf("%d",&new->data);
    head->prev=new;
    new->next=head;
    new->prev=NULL;
    head=new;
    
}
void addatend(){
     struct node *new,*p;
      new=createnode();
    printf("Enter the value :");
    scanf("%d",&new->data);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new;
    new->prev=p;
    new->next=NULL;
}
void addatindex9(){
    struct node *new,*p=head;
     new=createnode();
    int j,i;
    printf("Enter the value and index :");
    scanf("%d",&new->data);
    printf("Enter the index :");
    scanf("%d",&i);
    for(j=1;j<i;j++){
        p=p->next;
    }
    new->next=p->next;
    new->prev=p;
    p->next=new;
    p->next->prev=new;
}
void deleteatend(){
    struct node *p=head;
    if(head->next!=NULL)
    {
        while(p->next!=NULL){
        p=p->next;
    }
    p->prev->next=NULL;
    free(p);
    }
    else{
        head=NULL;
        free(head);
        printf("Head deleted.");
    }
}
void deleteatstart(){
    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteatvalue(){
struct node *p=head,*q=head->next;
 
    int j,i;
    scanf("%d",&i);
    while(q->data!=i){
        if(q==NULL){
            printf("Not found.");
        }
        else{
            p=p->next;
            q=q->next;
        }

    }
    p->next=q->next;
    q->next->prev=p;
    free(q);
    
}
void deleteatindex(){
    struct node *p=head,*q=head->next;
 
    int j,i;
    scanf("%d",&i);
    for(j=1;j<i;j++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next->prev=p;
    free(q);
    
}
void createll(){
    int ans=1;
    struct node *new,*temp;
    while(ans==1){
        new=createnode();
        printf("Enter the value of data :");
        scanf("%d",&new->data);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            new->prev=temp;
            temp=new;
        }
        printf("Enter 1:");
        scanf("%d",&ans);
    }
}
void display(){
    struct node *p=head;
    while(p!=NULL){
        printf("DATA :%d",p->data);
        p=p->next;
    }
}

int main(){
    createll();
   addatindex9();
    display();
}