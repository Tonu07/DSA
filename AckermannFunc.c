#include<stdio.h>
int Ackermann(int m,int n){
    if(m==0&&n!=0){
        return n+1;
    }
    else if(m!=0&&n==0){
        return Ackermann(m-1,1);
    }
    else{
        return Ackermann(m-1,Ackermann(m,n-1));
    }
}
int main(){
    int m,n;
    printf("Enter the value m:");
    scanf("%d",&m);
    printf("Enter the vlaue n:");
    scanf("%d",&n);
    int r=Ackermann(m,n);
    printf("The result=%d\n",r);
}