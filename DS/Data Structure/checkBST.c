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
int isBST(struct node *r){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(r->left)){
            return 0;
        }
        if(prev!=NULL && r->data<=prev->data){
            return 0;
        }
        prev=r;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
int main(){
    struct node *p,*p1,*p2,*p3,*p4,*p5;
    p=createnode(11);
    p1=createnode(5);
    p2=createnode(15);
    p3=createnode(2);
    p4=createnode(9);
    p5=createnode(25);
    //       11
    //    5     15
    //  2   9     25
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
   //preordertrav(p);
   //postorder(p);
   //inorder(p);
   printf("%d",isBST(p));
}