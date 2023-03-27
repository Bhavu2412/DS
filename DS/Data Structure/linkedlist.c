#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
}; 
void linkedlist(struct Node *ptr){
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=NULL);
}
int addstart(struct Node *head,int dt){
    struct Node addition;
    addition=(struct Node *)malloc(sizeof(struct Node));
    addition-> data=dt;
    addition-> next=head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *last;
    int b;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    last=(struct Node *)malloc(sizeof(struct Node));
    
    head -> data=1;
    head -> next=second;
    second -> data=2;
    second -> next=third;
    third -> data=3;
    third -> next=last;
    last -> data=12;
    last -> next=NULL;
    head = addstart(add,7);
    
    linkedlist(head);
    //      To add at the start.
    // printf("Enter the value of new data to be added first :");
    // scanf("%d",&b);
    
    // a=add;
    // linkedlist(a);

    //      To add at the end.
    // printf("Enter the value of new data to be added last :");
    // scanf("%d",&b);
    // last -> next=add;
    // add -> data=b;
    // add -> next=NULL;
    // linkedlist(a);


    

}