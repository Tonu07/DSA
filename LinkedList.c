#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void create() {
    int n;
    printf("Enter the value for node: ");
    scanf("%d", &n);
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = n;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        printf("Node with data %d created and set as head.\n", n);
    } else {
        struct node *temp;
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        printf("Node with data %d added to the list.\n", n);
    }
}
void traverse() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("Traversing........\n");
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
void insertion() {
    struct node *newnode, *current, *prev;
    int pos, count = 0;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the node position where you want to insert: ");
    scanf("%d", &pos);
    printf("Enter the node data that you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        printf("Node with data %d inserted at position 1.\n", newnode->data);
        return;
    }
    current = head;
    prev = NULL;
    while (current != NULL && count < pos - 1) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == NULL && count < pos - 1) {
        printf("Position %d is out of bounds. Node not inserted.\n", pos);
        free(newnode); 
        
        return;
    }
    prev->next = newnode;
    newnode->next = current;
    printf("Node with data %d inserted at position %d.\n", newnode->data, pos);
}
void deletion() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp, *prev;
    int pos, count = 0;
    printf("Enter the node position you want to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        temp = head;
        head = head->next;
        printf("Node with data %d deleted from position 1.\n", temp->data);
        free(temp);
        return;
    }

    temp = head;
    prev = NULL;
    while (temp != NULL && count < pos - 1) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position %d is out of bounds. Nothing to delete.\n", pos);
        return;
    }
    prev->next = temp->next;
    printf("Node with data %d deleted from position %d.\n", temp->data, pos);
    free(temp);
}
int main() {
    while (1) {
        printf("\n......Menu.....\n");
        printf("1. Creation\n");
        printf("2. Traversing\n");
        printf("3. Insertion\n");
        printf("4. Deletion\n");
        printf("5. Exit\n");
        int op;
        printf("Enter Your option: ");
        scanf("%d", &op);
        if (op == 5) {
            break;
        }
        switch (op) {
            case 1:
                create();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insertion();
                break;
            case 4:
                deletion();
                break;
            default:
                printf("You entered a wrong option\n");
        }
    }
    return 0;
}
/*My own Code
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head=NULL;
void create(){
    while(1){
            printf("Enter your choice:(0 or 1):");
    int c;
    scanf("%d",&c);
    if(c==0){
        break;
    }
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the data:");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
}
void traverse(){
    struct node *temp;
   temp=head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void searching(){
    int num;
    printf("Enter num:");
    scanf("%d",&num);
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==num){
            printf("The number is found here\n");
            break;
        }
        else{
            temp=temp->next;
        }
    }
    printf("Not found\n");
}
void insertion(){
    printf("1.big 2.end 3.any\n");
    printf("Enter your choice:");
    int c;
    scanf("%d",&c);
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the data:");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=NULL;
    if(c==1){
       newnode->next=head;
       head=newnode;
    }
    else if(c==2){
         while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    }
    else{
        printf("Enter the pos:");
        int pos;
        scanf("%d",&pos);
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

}
void deletion(){
        struct node *temp,*pre;
    temp=head;
     printf("1.big 2.end 3.any\n");
    printf("Enter your choice:");
    int c;
    scanf("%d",&c);
    if(c==1){
        head=temp->next;
    }
    else if(c==2){
            pre=NULL;
                 while(temp->next!=NULL){
                     pre=temp;
        temp=temp->next;
                 }
                 free(temp->next);
                 pre->next=NULL;
    }
    else{
          printf("Enter the pos:");
        int pos;
        scanf("%d",&pos);
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
    }
}
int main(){

while(1){
    printf("..Menue..\n");
    printf("1.create\n");
    printf("2.traverse\n");
    printf("3.searching\n");
    printf("4.insertion\n");
    printf("5.deletion\n");
    printf("6.Exit\n");
    int op;
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op){
case 1:create();
break;
case 2:traverse();
break;
case 3:searching();
break;
case 4:insertion();
break;
case 5: deletion();
break;
default: printf("You have enterd wrong option\n");
    }
}
}

*/