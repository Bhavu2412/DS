#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *createnode(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    return temp;
}
int main(){
    struct node *p,*p1,*p2;
    p=createnode(1);
    p1=createnode(12);
    p2=createnode(13);
    p->left=p1;
    p->right=p2;
    printf("%d->%d<-%d",p1->data,p->data,p2->data);
}