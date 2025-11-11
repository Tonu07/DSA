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
    printf("Enter your option :\n1.YES(press 1)\n2.NO(press 0)\n");
    scanf("%d",&c);
    if(c==0){
        break;
    }
newnode=(struct node*)malloc(sizeof(struct node));
int n;
printf("Enter your data for doubly linked list:");
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
printf("Doubly Linked list :\n");
temp=head;
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
//Insertion of doubly linked list at any position
struct node *nn,*prep,*postp,*exactp;
nn=(struct node*)malloc(sizeof(struct node));
int v;
printf("Enter your insertion data:");
scanf("%d",&v);
nn->data=v;
nn->next=NULL;
nn->prev=NULL;
int pos;
printf("Enter the position where you want to insert:");
scanf("%d",&pos);
int i=1;
temp=head;
while(i<pos-1){
temp=temp->next;
i++;
}
nn->prev=temp;
nn->next=temp->next;
temp->next=nn;
nn->next->prev=nn;
temp=head;
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
return 0;
}