#include<stdio.h>
#include<string.h>

const int max=10;

char arr[100];
int top=-1;
void revstr(char *str1)  
{  
    // declare variable  
    int i, len;
    char temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
} 
void push(char data)
{
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        top=top+1;
        arr[top]=data;
        printf("Pushed %c\n",data);
    }
}

char pop(){
    if(top==-1){
        printf("Stack Empty\n");
        return 0;
    }
    else{
        char temp=arr[top];
        top=top-1;
        return temp;
    }
}

void display(){
    if(top==-1){
        printf("Stack Empty\n");
    }
    else{
        int i;
        for(i=top;i>=0;i--){
            printf("%c\n",arr[i]);
        }
    }
}

int peek(){
    if(top==-1){
        printf("Stack Empty\n");
        return 0;
    }
    else{
        return arr[top];
    }
}

int Prior(char temp){
    if(temp=='%')
    {
        if(arr[top]==temp){
            printf("POPPED %c\n",arr[top]);
            return 1;
        }
        return 0;
    }
    else if(temp=='*' || temp=='/'){
        if(arr[top]=='%' || arr[top]=='/' || arr[top]=='*'){
            printf("POPPED %c\n",arr[top]);
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(temp=='+' || temp=='-'){
        if(arr[top]=='(')
        {
            return 0;
        }
        else{
            printf("POPPED %c\n",arr[top]);
            return 1;
        }
    }
    else if(temp=='('){
        return 0;
    }
    else if(temp==')'){
        printf("POPPED %c\n",arr[top]);
        return 1;
    }
    
}

int main(){
    char infix[100],postfix[100],temp,popped;
    int n,i=0,j=0;
    printf("Enter Infix String\n");
    gets(infix);
   revstr(infix);
    printf("%s",infix);
    n=strlen(infix);
    while(i!=n)
    {
        // if(infix[i]=='('){
        //     infix[i]=')';
        // }
        // if(infix[i]==')'){
        //     infix[i]='(';
        // }
        temp=infix[i];
        if(temp>'0' && temp<'9')
        {
            postfix[j]=temp;
            j++;
        }
        else{
            while(Prior(temp)==1 && top!=-1)
            {
                popped=pop();
                if(popped!='('){
                    postfix[j]=popped;
                    j++;
                }
            }
           if(temp!=')')
           { 
            push(temp);
           }
        }
        i++;
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    revstr(postfix);
    for(i=0;i<n;i++)
    {
        printf("%c",postfix[i]);
    }
    
    return 0;
}