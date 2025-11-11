#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main() {
    struct node *head, *newnode, *temp, *nn, *prevpos, *nextpos;
    head = 0;
    int c;
    while(1){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data you want to input:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head==0){
            head=temp= newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("1)continue(press 1)\n2)stop(press 0)\n");
        scanf("%d", &c);
        if(c == 0){
            break;
        }
    }
    nn = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert:");
    scanf("%d", &nn->data);
    nn->next = 0;

    int value_to_insert = nn->data;
    int inserted = 0;
    if (head ==0||value_to_insert<head->data) {
        printf("Does not find\n");
        inserted=0;
    }
    else {
        prevpos = head;
        while (prevpos!=0&& prevpos->next !=0&&prevpos->next->data<= value_to_insert) {
            if (prevpos->data == value_to_insert) {
                printf("Value %d already exists in the linked list. Cannot insert.\n", value_to_insert);
                inserted = 0;
                break;
            }
            prevpos = prevpos->next;
        }
        if (!inserted){
            if (prevpos!=0&&prevpos->data==value_to_insert) {
                printf("Cannot insert\n",value_to_insert);
            } else {
                 if (prevpos!=0&& value_to_insert>prevpos->data){
                    nn->next=prevpos->next;
                    prevpos->next=nn;
                    inserted=1;
                } else {
                    printf("Does not inserted.\n", value_to_insert);
                }
            }
        }
    }
    if (head!=0) {
        printf("\nResulting Linked List:\n");
        temp=head;
        while(temp!=0){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    } else {
        printf("Linked list is empty.\n");
    }
}
