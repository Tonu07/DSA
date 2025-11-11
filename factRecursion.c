#include<stdio.h>
int fact(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int r=fact(n);
    printf("The result=%d\n",r);
}