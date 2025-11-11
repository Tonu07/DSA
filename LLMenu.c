#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create(){
struct node *newnode,*temp;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the number:");
int x;
scanf("%d",&x);
newnode->data=x;
newnode->next=NULL;
if(head==NULL){
   head=newnode;
}
else{
        temp=head;
    while(temp->next!=NULL){
          temp=temp->next;
          }
          temp->next=newnode;
}

}
void Insertion(){
    struct node *temp,*newnode;
printf("1.Begining \n2.End \n3.After a position \n4.Before a position\n");
int op;
printf("Enter ur option:");
scanf("%d",&op);
int n;
printf("Enter the data for insertion:");
scanf("%d",&n);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=n;
newnode->next=NULL;
switch(op){
case 1:temp=head;
newnode->next=temp;
head=newnode;
break;
case 2:temp=head;
while(temp->next!=NULL){
        temp=temp->next;
      }
temp->next=newnode;
break;
case 3:
printf("Enter the position:");
   int pos;
scanf("%d",&pos);
int i=1;
temp=head;
while(temp!=NULL&&i<pos){
    temp=temp->next;
    i++;
}
newnode->next=temp->next;
temp->next=newnode;
break;
case 4:
printf("Enter the position:");
int posA;
scanf("%d",&posA);
int j=1;
temp=head;
while(j<posA-1){
    temp=temp->next;
    j++;
}
newnode->next=temp->next;
temp->next=newnode;
break;
default:printf("Entered wrong option\n");
}
}
void Deletion(){
   struct node *temp,*prev,*current,*nn;
printf("1.Begining \n2.End \n3.After a position \n4.Before a position\n");
int op;
printf("Enter ur option:");
scanf("%d",&op);
switch(op){
case 1:temp=head;
head=head->next;
free(temp);
break;
case 2:temp=head;
while(temp->next!=NULL){
        prev=temp;
      temp=temp->next;
      }
        prev->next=NULL;
free(temp);
break;
case 3:
printf("Enter the position:");
int pos;
scanf("%d",&pos);
int i=1;
temp=head;
while(i<pos&&temp!=NULL){//v check it case pos may be very heigh
    temp=temp->next;
    i++;
}
current=temp->next;
temp->next=current->next;
free(current);
break;
case 4:
printf("Enter the position:");
int posB;
scanf("%d",&posB);
int j=1;
temp=head;
while(j<pos-2&&temp!=NULL){
    temp=temp->next;
    j++;
}
nn=temp->next;
temp->next=nn->next;
free(nn);
break;
default:printf("Entered wrong option\n");
}
}
void traversing(){
    struct node *temp=head;
    if(head==NULL){
       printf("Empty\n");
              }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
while(1){
    printf("....Menue....\n");
    printf("1.Creation\n");
    printf("2.Insertion\n");
    printf("3.Deletion\n");
    printf("4.Traversing\n");
    printf("5.Exit\n");
    printf("Enter your option:");
    int c;
    scanf("%d",&c);
    if(c==5){
        break;
    }
    switch(c){
        case 1:create();
        break;
        case 2:Insertion();
        break;
        case 3:Deletion();
        break;
        case 4:traversing();
        break;
        default: printf("You have entered wrong option\n");
    }
}
}
