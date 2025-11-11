#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
struct node *head,*newnode,*temp;
head=NULL;
int c;
while(1){
printf("1.Yes\n0.No\n");
scanf("%d",&c);
if(c==0){
    break;
}
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data=");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL){
    head=temp=newnode;
}
else{
    temp->next=newnode;
    temp=newnode;
}
temp->next=head;
}
temp=head;
printf("Traversing of a circular linked list:\n");
while(temp->next!=head){
    printf("%d\n",temp->data);
    temp=temp->next;
}
printf("%d\n",temp->data);
}