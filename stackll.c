#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=0;
void push(){
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(top==0){
    newnode->next=0;
    top=newnode;
    printf("%d push as head successfully\n",x);
    }
    else{
    newnode->next=top;
    top=newnode;
    printf("%d push successfully\n",x);
    }
}
void pop(){
  struct node *temp;
  temp=top;
  printf("The poped value=%d\n",top->data);
  top=temp->next;
 free(temp);
}
void peek(){
        printf("The peek value=%d\n",top->data);
}
void display(){
   struct node *temp;
   temp=top;
   while(temp!=0){
    printf("%d\n",temp->data);
    temp=temp->next;
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