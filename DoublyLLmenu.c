#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void create(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    newnode->data=x;
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
void traverse(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    while(1){
    printf(".....Menue.....\n");
    printf("1.Creation\n");
    printf("2.traversing\n");
    ptrintf("3.Insertion\n");
    printf("4.deletion\n");
    printf("5.Exit\n");
    int op;
    printf("Enter your option:");
    scanf("%d",&op);
      if(op==5){
        break;
    }
    switch(op);
    case 1:craete();
    break;
    case 2:traverse();
    break;
    case 3:printf("3.Insertion\n");
    break;
    case 4:printf("4.deletion\n");
    break;
    default:printf("You have enter wrong option\n");

}
}