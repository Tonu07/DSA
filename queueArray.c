#include<stdio.h>
//Implementation of queue using arrary
#define n 5
int queue[n];
int front=-1,rear=-1;
void enqueue(){
    int x;
    printf("Enter the number=");
    scanf("%d",&x);
    if(rear==n-1){
        printf("The queue is full\n");
    }
    else if(front==-1&&rear==-1){
        front++;
        rear++;
        queue[rear]=x;
        printf("%d enqueued successfully\n",x);
    }
    else{
        rear++;
        queue[rear]=x;
        printf("%d enqueued successfully\n",x);
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("queue empty\n");
        }
        else if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            printf("The dequeued value=%d\n",queue[front]);
            front++;
        }
}
void peek(){
    if(front=-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("The peek value =%d\n",queue[front]);
    }
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
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
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.peek\n");
printf("4.Display\n");
int op;
printf("Enter your option :");
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
default:printf("Enter the wrong option\n");
}
}
    return 0;
}