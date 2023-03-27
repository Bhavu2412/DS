#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node *createnode(int d){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=d;
    return new;
}
struct node * createbst(struct node *root,int val){
    struct node *new,*temp;
    int n;
        if(root==NULL){
        return createnode(val);
        }
        else if(root->data>val){
            printf(" left %d \n", root->data);
            root->left= createbst(root->left,val);
        }
        else{
             printf(" right %d \n", root->data);
            root->right= createbst(root->right,val);

        }
    
    return root;
}
void inorder(struct node *root){
    if(root == NULL)
    {return;}
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    
}
void preorder(struct node *root){
    if(root == NULL)
    {return;}
    printf("%d\t",root->data);
    inorder(root->left);
    inorder(root->right);
    
}
void postorder(struct node *root){
    if(root == NULL)
    {return;}
    inorder(root->left);
    inorder(root->right);
    printf("%d\t",root->data);
    
}
void main(){
    int c=0,n;
    struct node *root=NULL;
    while(c<2){
        printf("\nEnter choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : 
            {
                
                if(root==NULL)
                {printf("Enter the root data : ");
                scanf("%d",&n);
                root = createbst(root,n);
                }
                else
                {printf("Enter the data : ");
                scanf("%d",&n);
                // printf("root %d \n",root->data);
                    createbst(root,n);
                }
                break;
            }
            
        }
    }
    inorder(root);
}