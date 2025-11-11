#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *front=0,*rear=0;
void enqueue(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
int x;
printf("Enter the number=");
scanf("%d",&x);
newnode->data=x;
newnode->next=NULL;
if(front==0&&rear==0){
    front=rear=newnode;
}
else{
 rear->next=newnode;
 rear=newnode;
}
}
void dqueue(){
if(front ==0&&rear==0){
printf("The queue is empty\n");
}
else{
    struct node *temp;
    temp=front;
    front=temp->next;
    free(temp);
}
}
void display(){
    printf("The queue->\n");
    struct node *temp;
    temp=front;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    while(1){
        printf("...Menue...\n");
        printf("1.enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        int op;
        printf("Enter your option:");
        scanf("%d",&op);
        if(op==4){
            break;
        }
        switch(op){
            case 1:enqueue();
            break;
            case 2:dqueue();
            break;
            case 3:display();
            break;
            default: printf("You entered wrong option\n");
        }
    }
}