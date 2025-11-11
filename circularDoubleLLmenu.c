#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void creation(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the data for your node: ");
    scanf("%d",&n);
    newnode->data=n;
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
        printf("%d fixed as head\n",newnode->data);
    }
     else{
        temp=head->prev;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
        printf("The number %d added to circular linked list.\n",newnode->data);
    }
}
void traversing(){
    struct node *temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Traversing the doubly circular linked list:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
        if(temp==head)break;
    }
}
void insert(){
    int op;
    printf("1.Beginning\n2.Ending\n3.Any position\n4.Before value\n5.After value\n");
    scanf("%d",&op);
    struct node *newnode,*temp,*pre,*post;
    newnode=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the data for your node: ");
    scanf("%d",&n);
    newnode->data=n;
    if(op==1){
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            temp=head->prev;
            newnode->next=head;
            newnode->prev=temp;
            temp->next=newnode;
            head->prev=newnode;
            head=newnode;
        }
    }
    else if(op==2){
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            temp=head->prev;
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=head;
            head->prev=newnode;
        }
    }
    else if(op==3){
        int pos;
        printf("Enter the position where you want to insert: ");
        scanf("%d",&pos);
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        post=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=post;
        post->prev=newnode;
    }
     else if(op==4){
        int val;
        printf("Enter the value before which you want to insert: ");
        scanf("%d",&val);
        temp=head;
        while(temp->data!=val){
            temp=temp->next;
            if (temp==head) {
                printf("Value not found.\n");
                return;
            }
        }
        pre=temp->prev;
        pre->next=newnode;
        newnode->prev=pre;
        newnode->next=temp;
        temp->prev=newnode;
        if(temp==head)
            head=newnode;
    }
    else{
        int val;
        printf("Enter the value after which you want to insert: ");
        //input x and put it in newnode
        scanf("%d",&val);
        temp=head;
        while(temp->data!=val){
            temp=temp->next;
            if(temp==head){
                printf("Value not found.\n");
                return;
            }
        }
        post=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=post;
        post->prev=newnode;
    }
}
void deletion(){
    struct node *temp;
    int op;
    printf("1.Beginning\n2.Ending\n3.Any position\n");
    scanf("%d", &op);
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(op==1){
        if(head->next==head){
            free(head);
            head=NULL;
        }
        else{
            temp=head;
            struct node *last=head->prev;
            head=head->next;
            last->next=head;
            head->prev=last;
            free(temp);
        }
    }
    else if(op==2){
        if (head->next==head) {
            free(head);
            head = NULL;
        }
        else{
            temp=head->prev;
            temp->prev->next=head;
            head->prev=temp->prev;
            free(temp);
        }
    }
     else{
        int pos;
        printf("Enter the position you want to delete: ");
        scanf("%d",&pos);
        temp=head;
        for (int i=1;i<pos;i++){
            temp=temp->next;
        }
        if(temp==head)
            head=head->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void search(){
    int n;
    printf("Enter the data you want to search: ");
    scanf("%d",&n);
    int pos=1,found=0;
    struct node *temp=head;

    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        if (temp->data==n){
            printf("The position of %d is = %d\n", n, pos);
            found++;
        }
        temp=temp->next;
        pos++;
        if(temp==head) break;
    }
    printf("%d appears in the list %d times\n", n, found);
}
int main(){
    int c;
    while (1) {
        printf("Do you want to continue (1 or 0): ");
        scanf("%d",&c);
        if (c==0) {
            break;
        }
        printf(".....Menu.....\n");
        printf("1.Creation\n");
        printf("2.Traversing\n");
        printf("3.Insertion\n");
        printf("4.Deletion\n");
        printf("5.Searching\n");
        printf("6.Exit\n");
        int op;
        printf("Enter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1:creation();
            break;
            case 2:traversing();
             break;
            case 3:insert();
            break;
            case 4:deletion();
             break;
            case 5:search();
             break;
            default:printf("You have entered a wrong option\n");
        }
    }
}