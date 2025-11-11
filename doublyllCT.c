#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
int main(){
struct node *head,*newnode,*temp;
head=NULL;
int c;
while(1){
printf("Enter your option:\n1)Yes(press 1)\n2)No(press 0)\n");
scanf("%d",&c);
if(c==0){
    break;
}
newnode=(struct node*)malloc(sizeof(struct node));
int n;
printf("Enter the data for newnode:");
scanf("%d",&n);
newnode->data=n;
newnode->next=NULL;
newnode->prev=NULL;
if(head==NULL){
    head=temp=newnode;
}
else{ 
temp->next=newnode;
newnode->prev=temp;
temp=newnode;
}
}
temp=head;
printf("Traversing of a doubly Linked list:\n");
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
}