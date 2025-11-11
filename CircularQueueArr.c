#include<stdio.h>
#define n 5
int queue[n];
int front=-1,rear=-1;
void push(){
    int x;
printf("Enter the number:");
scanf("%d",&x);
if(front==-1&&rear==-1){
front=rear=0;
queue[rear]=x;
}
else if((rear+1)%n==front){
    printf("FULL\n");
}
else{
    rear=(rear+1)%n;
    queue[rear]=x;
}
}
void pop(){
if(front==-1&&rear==-1){
    printf("Empty\n");
}
else if(front==rear){
    front=rear=-1;
}
else{
        printf("The dequed value=%d\n",queue[front]);
    front++;
}
}
void display(){
    printf("The circular queue:\n");
    for(int i=front;i<=rear;i=(i+1)%n){
            printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int c;
    while(1){
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your option:");
        scanf("%d",&c);
        if(c==4){
            break;
        }
        switch(c){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        default:printf("Enter wrong option\n");
        }
    }
}