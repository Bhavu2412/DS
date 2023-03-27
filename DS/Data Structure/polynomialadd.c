#include<stdio.h>
#include<stdlib.h>
struct node{
    int data,pow;
    struct node *next;
};
struct node *start,*start1,*start2;
struct node *createnode(){
    struct node *new=(struct node *)malloc(sizeof(struct node ));
    new->next=NULL;
    return new;
}
struct node *insert(struct node *head,int n){
    struct node *new,*temp;
    while(n>0){
        new=createnode();
        printf("Enter data  :");
        scanf("%d",&new->data);
         printf("Enter power  :");
        scanf("%d",&new->pow);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
           temp->next=new;
            temp=new;
        }
        n--;
    }
    return head;//

}
void add(int c,int p){
    struct node *sum,*temp;
    
    sum=createnode();
    sum->data=c;
    sum->pow=p;
    if(start2==NULL){
        start2=sum;
        temp=sum;
    }
    else{
        temp->next=sum;
        temp=sum;
    }
}
void display(struct node *head){
    struct node *p=head;
    if(p==NULL){
        printf("Empty.\n");
    }
    else{
        while(p!=NULL){
            printf(" %d X^%d +",p->data,p->pow);
            p=p->next;
        }
    }
}
int main(){
    struct node *t1,*t2;
    int c,p;
    start=insert(start,3);
    start1=insert(start1,3);
    t1=start;
    t2=start1;
    while(t1!=NULL && t2!=NULL){
        if(t1->pow==t2->pow){
            c=t1->data+t2->data;
            p=t2->pow;
            add(c,p);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->pow<t2->pow){
            c=t2->data;
            p=t2->pow;
             add(c,p);
            t2=t2->next;
        }
        else if(t1->pow>t2->pow){
             c=t1->data;
            p=t1->pow;
             add(c,p);
            t1=t1->next;
        }
    }
    while(t1!=NULL){
        add(t1->data,t1->pow);
        t1=t1->next;
    }
    while(t2!=NULL){
        add(t2->data,t2->pow);
        t2=t2->next;
    }
    display(start2);
}