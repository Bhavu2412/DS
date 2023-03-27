// paranthesis balancing using stacks

#include<stdio.h>
const int max=10;
char arr[10];
int top=-1;
void push(char val){
    if(top<max){
        top=top+1;
        arr[top]=val;
    }
    else{
        printf("Stack is full.");
    }
}
void pop(){
    if(top!=-10)
    top=top-1;
    else
    printf("Stack is empty.");
}
void display(){
    int i;
    if(top!=-1){
        for(i=top;i>=0;i--){
        printf("DATA :%d\n",arr[i]);
        }
    }
    else{
        printf("Stack is empty.");
    }
}
int main(){
    char exp[20],i=0;
    printf("Enter the expression :");
    gets(exp);
        while(exp[i]!='\0'){
            if(exp[i]== '{' ||exp[i]== '[' || exp[i]== '(' ){
                push(exp[i]);
            }
            else if(exp[i]== '}' && arr[top]=='{'||exp[i]== ']' && arr[top]=='['||exp[i]== ')' && arr[top]=='('){
                pop();
            }
            i++;
        }
        if(top==-1){
            printf("Paranthesis matched.");

        }
        else{
            printf("Paranthesis not matched.");
        }
       
}