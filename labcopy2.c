#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* mergeSortedLists(struct node* head1, struct node* head2) {
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    struct node* result=NULL;
    if(head1->data <= head2->data){
        result=head1;
        result->next=mergeSortedLists(head1->next,head2);
    } else{
        result=head2;
        result->next=mergeSortedLists(head1,head2->next);
    }
    return result;
}
void printList(struct node *node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
int main(){
    struct node *head1, *newnode, *temp;
    head1=NULL;
    int c;
    printf("Creating 1st sorted linked list:\n");
    while(1){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for 1st LL node (in sorted order): ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head1==NULL){
            head1=temp=newnode;
        } else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (press 0 or 1)?: ");
        scanf("%d",&c);
        if(c==0){
            break;
        }
    }
    printf("First Linked List: ");
    printList(head1);
    struct node *head2, *newnode2, *temp2;
    head2=NULL;
    int c2;
    printf("\nCreating 2nd sorted linked list:\n");
    while(1){
        newnode2=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for 2nd LL node (in sorted order): ");
        scanf("%d",&newnode2->data);
        newnode2->next=NULL;
        if(head2==NULL){
            head2=temp2=newnode2;
        } else{
            temp2->next = newnode2;
            temp2 = newnode2;
        }
        printf("Do you want to continue (press 0 or 1)?: ");
        scanf("%d",&c2);
        if (c2==0) {
            break;
        }
    }
    printf("Second Linked List: ");
    printList(head2);
    struct node* mergedHead = mergeSortedLists(head1, head2);
    printf("\nAfter merging the two sorted linked lists:\n");
    printList(mergedHead);
    return 0;
}