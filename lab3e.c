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
if (ihead != NULL) {
        itemp->next = ihead;
printf("Your first circular Linked list:\n");
traversing(head);
struct node *head2,*newnode2,*temp1,*temp2;
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
 struct node *rhead=NULL;
    struct node *rtemp=NULL;
     temp1=head;
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
        while (temp1->next!=head&&temp2->next!=head2){
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
        if(temp1!=head){
            rtemp->next=temp1;
        }
        else if(temp2!=head){
            rtemp->next=temp2;
        }
    }
    rtemp->next=rhead;
    printf("Merged Linked List:\n");
   while(rhead->next!=rhead){
    printf("%d\n",rhead->data);
    rhead=rhead->next;
}
}
}