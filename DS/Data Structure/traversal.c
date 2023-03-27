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
void preordertrav(struct node * r){
    
    if(r!=NULL){
        printf("Data :%d",r->data);
        preordertrav(r->left);
        preordertrav(r->right);
    }
}
void inorder(struct node * r){
    if(r!=NULL){
        inorder(r->left);
        printf("Data :%d",r->data);
        inorder(r->right);
    }
}
void postorder(struct node * r){
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("Data :%d",r->data);
    }
}
int main(){
    struct node *p,*p1,*p2,*p3,*p4,*p5;
    p=createnode(1);
    p1=createnode(12);
    p2=createnode(13);
    p3=createnode(16);
    p4=createnode(20);
    p5=createnode(25);
    //       1
    //   12    13
    // 16  20     25
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
   //preordertrav(p);
   //postorder(p);
   inorder(p);
}