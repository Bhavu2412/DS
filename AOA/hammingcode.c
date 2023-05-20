//haming code
#include<stdio.h>
int main(){
    int in[4],ans[7];//1d0 0d1 1d2 0p3 0d4 1p5 0p6
    // for(int i=0;i<4;i++)
    // scanf("%d",&in[i]);
    // for(int i=0;i<3;i++){
    //     ans[i]=in[i];
    // }
    // ans[4]=in[3];
    // ans[6]=ans[4]^ans[0]^ans[2];
    // ans[5]=ans[4]^ans[0]^ans[1];
    // ans[3]=ans[0]^ans[1]^ans[2];
    // printf("The bit sequence is :");
    // for(int i=0;i<7;i++)
    // printf("%d",ans[i]);

    printf("Enter the recived sequence :");
    for(int i=0;i<7;i++){
        scanf("%d",&ans[i]);
    }
    if(ans[6]==(ans[4]^ans[0]^ans[2]) && ans[5]==(ans[4]^ans[0]^ans[1]) && ans[3]==(ans[0]^ans[1]^ans[2])){
        printf("Congratulation there is no error\n");
    }
    else{
        int c1=ans[6]^ans[4]^ans[0]^ans[2];
        int c2=ans[5]^ans[4]^ans[0]^ans[1];
        int c3=ans[3]^ans[0]^ans[1]^ans[2];
        int c=4*c1+2*c2+c3;
        printf("There is an error\n");
        if(ans[c]==0){
            ans[6-c+1]=1;
        }
        else{
            ans[6-c+1]=0;
        }
    }
    for(int i=0;i<3;i++){
            printf("%d",ans[i]);
        }
        printf("%d",ans[4]);
}