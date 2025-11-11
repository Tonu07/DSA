#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main(){
    struct node *newnode,*temp;
while(1){
printf("1.yes(1)\n2.No(0)\n");
int op;
scanf("%d",&op);
if(op==0){
    break;
} 
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
int x;
scanf("%d",&x);
newnode->data=x;
newnode->next=NULL;
if(head==NULL){
    head=temp=newnode;
}
else{
    temp->next=newnode;
    temp=newnode;
}
}
temp=head;
int c=0;
while(temp!=NULL){
    temp=temp->next;
    c++;
}
printf("The value of c=%d\n",c);
c=c/2;
temp=head;
int i=0;
while(i<c){
    temp=temp->next;
    i++;
}
printf("The middle data=%d ",temp->data);
}