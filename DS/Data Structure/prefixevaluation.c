// evaluation of prefix expression
// stacks using array
#include<stdio.h>
const int max=10;
int arr[10];
int top=-1;
void push(int val){
    if(top<max){
        top=top+1;
        arr[top]=val;
        printf("pushed.");
    }
    else{
        printf("Stack is full.");
    }
}
int pop(){
    int val=arr[top];
    if(top!=-10){
        top=top-1;
        return val;
        printf("poped");
    }
    else{
    printf("Stack is empty.");
    return -1;
    }
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
    char exp[20];
    int c,i=0;
    printf("Enter the expression :");
    gets(exp);
    while(exp[i]!='\0'){
        i++;
    }
    while(i!=-1){
        if(exp[i]>='0' && exp[i]<='9'){
            push(exp[i]-'0');
        }
        else{
            int b=pop();
            int a=pop();
            switch(exp[i]){
                case '+':
                c=a+b;
                break;
                case '-':
                c=a-b;
                break;
                case '*':
                c=a*b;
                break;
                case '/':
                c=a/b;
                break;
                case '%':
                c=a%b;
                break;

            }
            push(c);
        }
        i--;
    }
    printf("The evaluation is :%d",arr[top]);
}