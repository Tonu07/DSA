#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=0,*rear=0;
void enqueue(){
    int x;
printf("Enter the number:");
scanf("%d",&x);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=0;
if(front==0&&rear==0){
    front=rear=newnode;
}
else{
    rear->next=newnode;
    rear=newnode;
}
}
void dequeue(){
if(front==0&&rear==0){
    printf("queue is empty\n");
}
else{
    struct node *temp;
    temp=front;
    front=temp->next;
    free(temp);
}
}
void peek(){
    if(front==0&&rear==0){
    printf("queue is empty\n");
}
    printf("The peek value=%d\n",front->data);
}
void display(){
    printf("The queue element=\n");
     if(front==0&&rear==0){
    printf("queue is empty\n");
}
else{
   struct node *temp;
   temp=front;
   while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->next;
   }
}
printf("\n");
}
int main(){
    int c;
    while(1){
           printf("Enter your option :(press 0 or 1)");
    scanf("%d",&c);
    if(c==0){
        break;
    }
    printf("...Menue...\n");
    printf("1.enueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    int op;
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op){
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:peek();
break;
case 4:display();
break;
default:printf("You enterd wrong option\n");
    }
}
}