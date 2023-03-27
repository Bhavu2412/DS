#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head;
struct node *createnode(){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head;
    return temp;
};
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
void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("No linked list found.\n");
    }
    else{
        do{
            printf("Data :%d\n",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}
void addatstart(){
    struct node *new,*temp;
    new=createnode();
    printf("Enter the value of new node :\n");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    temp->next=head;
}
void addatend(){
    struct node *new,*temp;
    new=createnode();
    printf("Enter the value of new node :\n");
    scanf("%d",&new->data);
    temp->next=new;
    new->next=head;
    
}
void addatindex(){
    struct node *p=head,*q=head->next,*new;
    new=createnode();
    int i=1,index;
    printf("Enter the index:\n");
    scanf("%d",&index);
    printf("Enter the data of new node :");
    scanf("%d",&new->data);
    while(index>i){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=new;
    new->next=q;                      
}
void deleteatstart(){
    struct node *temp,*p;
    p=head;
    head=head->next;
    temp->next=head;
    free(p);
}
void deleteatend(){
    struct node *p=head,*q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
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
        if(q->next==head){
            printf("The value is not found.\n");
        }
        i++;
    }
    p->next=q->next;
    free(q);
}
int main(){
    createll();
    display();
    addatstart();
    addatend();
    addatindex();
    deleteatstart();
    deleteatend();
    deletewithvalue();
    deleteatindex();
    display();
}