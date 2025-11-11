#include<stdio.h>
#define n 5
int stack[n];
int top=-1;
void push(){
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    if(top==n-1){
        printf("Stack is full\n");
    }
    else{
    top++;
    stack[top]=x;
    printf("%d push successfully\n",x);
}
}
void pop(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
    printf("You poped value=%d\n",stack[top]);
       top--;
    }
}
void peek(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("The peek value=%d\n",stack[top]);
    }
}
void display(){
    for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }
}
int main(){
    int c;
    while(1){
printf("Do you want to continue (press 0 or 1):");
scanf("%d",&c);
if(c==0){
    break;
}
printf("....Menue...\n");
printf("1.Push\n");
printf("2.pop\n");
printf("3.peek\n");
printf("4.Display\n");
int op;
printf("Enter your option :");
scanf("%d",&op);
switch(op){
case 1:push();
break;
case 2:pop();
break;
case 3:peek();
break;
case 4:display();
break;
default:printf("Enter the wrong option\n");
}
}
}