#include<stdio.h>
#include<stdlib.h>
 struct node{
     int data;
     struct node *next;
 };
int main(){
  struct node *head1,*newnode,*temp;
  head1=NULL;
  int c;
  while(1){
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data for 1st LL node:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(head1==NULL){
        head1=temp=newnode;
  }
  else{
       temp->next=newnode;
    temp=newnode;

      }
  printf("Do you want to continue(press 0 or 1)?:");
  scanf("%d",&c);
  if(c==0){
    break;
  }
}
struct node *T1=head1;
printf("Traversing LL 1:\n");
while(T1!=NULL){
    printf("%d ",T1->data);
    T1=T1->next;
}
printf("\n");
  struct node *head2,*newnode2,*temp2;
  head2=NULL;
  int c2;
  while(1){
  newnode2=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data for 2 nd LL node:");
  scanf("%d",&newnode2->data);
  newnode2->next=NULL;
  if(head2==NULL){
        head2=temp2=newnode2;
  }
  else{
    temp2->next=newnode2;
    temp2=newnode2;
  }
  printf("Do you want to continue(press 0 or 1)?:");
  scanf("%d",&c2);
  if(c2==0){
    break;
  }
}
struct node *T2=head2;
printf("Traversing LL 2:\n");
while(T2!=0){
    printf("%d ",T2->data);
    T2=T2->next;
}
printf("\n");
struct node *rtemp;
rtemp=head1;
while(rtemp->next!=NULL){
rtemp=rtemp->next;
}
rtemp->next=head2;
printf("After joining two linked list :\n");
while(head1!=NULL){
    printf("%d ",head1->data);
    head1=head1->next;
}
}
