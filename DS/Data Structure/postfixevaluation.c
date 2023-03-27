
#include<stdio.h>
int stack[20];
int top = -1;
int val=0;

void push(int x)
{
    top=top+1;
    stack[top] = x;
}

int pop()
{
    val=stack[top];
    top=top-1;
    return val;
}

int main()
{ int i=0;
    char exp[20];
    
    int n1,n2,n3,num;
    
    printf("Enter the expression : ");
    gets(exp);
    
    while(exp[i]!='\0')
    {
        if(exp[i]>='0'&& exp[i]<='9')
        {
            num=exp[i];
            push(num-'0');
        }
        else
        {
            n1 = pop();
            n2 = pop();
            printf("the n1 is %d",n1);
            printf("the n2 is %d",n2);
            switch(exp[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
            printf("the nos is %d",n3);
        }
      i++;
     printf("the i is %d",i);
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}