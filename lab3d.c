#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traversing(struct node *temp){
    struct node *head=temp;
while(temp->next!=head){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("%d\n",temp->data);
}
int main(){
struct node *head,*newnode,*temp;
head=NULL;
int c;
while(1){
    printf("Enter your option(1 or 0):");
    scanf("%d",&c);
     if(c==0){
        break;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter your node data for first circular LL=");
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
temp->next=head;
printf("Your first circular Linked list:\n");
traversing(head);
struct node *head2,*newnode2,*temp2;
head2=NULL;
int c2;
while(1){
    printf("Enter your option(1 or 0):");
    scanf("%d",&c2);
    if(c2==0){
        break;
    }
    newnode2=(struct node*)malloc(sizeof(struct node));
    int n2;
    printf("Enter your node data for second circular LL=");
    scanf("%d",&n2);
    newnode2->data=n2;
    newnode2->next=NULL;
    if(head2==NULL){
        head2=temp2=newnode2;
    }
    else{
        temp2->next=newnode2;
        temp2=newnode2;
    }
}
temp2->next=head2;
printf("Your second circular Linked list:\n");
traversing(head2);
printf("Joining two circular LL:\n");
temp2->next=head;
struct node *rhead,*rtemp;
rtemp=rhead=head;
while(rtemp->next!=head){
    rtemp=rtemp->next;
}
rtemp->next=head2;
traversing(rhead);
return 0;
}
