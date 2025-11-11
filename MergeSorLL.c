#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
int main(){
struct node *head1,*newnode1,*temp1,*head2,*newnode2,*temp2;
head1=NULL;
head2=NULL;
int c1;
while(1){
    printf("Do you want to continue(press 0 or 1)?:");
scanf("%d",&c1);
        if(c1==0){
            break;
        }
newnode1=(struct node*)malloc(sizeof(struct node));
int n1;
printf("Enter the data int Linked list 1 :");
scanf("%d",&n1);
newnode1->data=n1;
newnode1->next=NULL;
if(head1==NULL){
    head1=temp1=newnode1;
}
else{
  temp1->next=newnode1;
  temp1=newnode1;
}
}
temp1=head1;
printf("Linked list 1 traversing:\n");
while(temp1!=NULL){
    printf("%d\n",temp1->data);
    temp1=temp1->next;
}
int c2;
while(1){
    printf("Do you want to continue(press 0 or 1)?:");
    scanf("%d",&c2);
    if(c2==0){
        break;
    }
    newnode2=(struct node*)malloc(sizeof(struct node));
    int n2;
    printf("Enter the data for Linked List 2:");
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
temp2=head2;
printf("Linkes list 2 traversing:\n");
while(temp2!=NULL){
    printf("%d\n",temp2->data);
    temp2=temp2->next;
}
    struct node *rhead=NULL;
    struct node *rtemp=NULL;
     temp1=head1;
     temp2=head2;
    if (temp1==NULL){
        rhead=temp2;
    }
     else if(temp2==NULL){
        rhead=temp1;
    }
    else{
        if(temp1->data<=temp2->data){
            rhead=temp1;
            temp1=temp1->next;
        }
        else{
            rhead = temp2;
            temp2 = temp2->next;
        }
        rtemp=rhead;
        while (temp1!=NULL&&temp2!=NULL){
            if(temp1->data<=temp2->data){
                rtemp->next=temp1;
                temp1=temp1->next;
            }
            else{
                rtemp->next=temp2;
                temp2=temp2->next;
            }
            rtemp=rtemp->next;
        }
        if(temp1!=NULL){
            rtemp->next=temp1;
        }
        else if(temp2!=NULL){
            rtemp->next=temp2;
        }
    }
    printf("Merged Linked List:\n");
   while(rhead!=NULL){
    printf("%d\n",rhead->data);
    rhead=rhead->next;
}
return 0;
}
