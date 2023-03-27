#include<stdio.h>
char stack[20];
int top = -1;
char val;

void push(char x)
{
    top=top+1;
    stack[top] = x;
}

int pop()
{   char val=stack[top];
    top=top-1;
    return val;
    
}
int priority(char z){
    char x=z;
    if(x=='('){
        return 1;
    }
    else if(x== '*' || x== '/'){
        return 2; 
    }
    else (x== '+' || x== '-');{
      return 3;
    }
    return 0;
}
int main(){
    char str[20],y[20];
    int j=0,i=0;
    printf("Enter the expersion :");
   gets(str);
    while(str[i]!='\0'){
        if(str[i]>='0' && str[i]<='9'){
            y[j]=str[i];
            j++;
        }
        else if(str[i]==')'){
           while(stack[i]!='('){
            y[j]=pop();
            j++;
            }
        }
        else{
            if(priority(stack[top])>priority(str[i])){
            push(str[i]);
             y[j]=pop();
             j++;   
            }
            else{
            push(str[i]);    
            }
        }
        i++;
    }


}