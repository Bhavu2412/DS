#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *root;
struct node *createnode(int val){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->left=NULL;
    new->data=val;
    new->right=NULL;
    return new;
}
struct node *createBST(struct node *root,int val){
    if(root==NULL){
            root=createnode(val);
        }
    else if(val<root->data){
            printf("Left of %d",root->data);
            root->left=createBST(root->left,val);
        }
    else{
            printf("Right of %d",root->data);
            root->right=createBST(root->right,val);
        }  
    return root;
}
struct node *search(struct node *root,int s){

    if(root->data==s){
       return root;
    }
    else if(root->data<s){
       return search(root->right,s);
    }
    else if(root->data>s){
        return search(root->left,s);
    }
    if(root==NULL)
    return NULL;
}
void inorder(struct node *root){
    if(root!=NULL){
    inorder(root->left);
    printf("\t%d\t",root->data);
    inorder(root->right);
    }
}
void insert(struct node *root,int val){
    struct node *new=createnode(val),*prev;
    while(root!=NULL){
        prev=root;
        if(root->data==val){
            printf("Value cannot be added.");
        }
        else if(root->data<val){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    if(prev->data<val){
        prev->right=new;
    }
    else{
        prev->left=new;
    }
}
int main(){
    int ans=1,val;
    while(ans<2){
        printf("Enter 1:");
        scanf("%d",&ans);
        switch(ans){
            case 1:
                if(root==NULL){
                    printf("Enter the value :");
                    scanf("%d",&val);
                    root=createBST(root,val);
                }
                else {
                    printf("Enter the value :");
                    scanf("%d",&val);
                    createBST(root,val);
                }
            break;
        }
    }
    inorder(root);
    // struct node *g=search(root,6);
    // if(g!=NULL){
    //     printf("Found.");
    // }
    // else{
    //     printf("Not found.");
    // }
    printf("\n");
    insert(root,5);
    inorder(root);
}