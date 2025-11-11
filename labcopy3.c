#include<stdio.h>
#include<stdlib.h>
struct IntNode{
    int data;
    struct IntNode *next;
};
struct CharNode{
    char data;
    struct CharNode *next;
};
/*void printIntList(struct IntNode  *head);
void printCharList(struct CharNode *head);
void freeIntList(struct IntNode *head);
void freeCharList(struct CharNode *head);*/
void printIntList(struct IntNode *head) {
    if (head==NULL){
        printf("Integer list is empty.\n");
        return;
    }
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void printCharList(struct CharNode *head){
    if(head==NULL){
        printf("Character list is empty.\n");
        return;
    }
    while(head!=NULL){
        printf("%c ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main() {
    struct IntNode *int_head=NULL;
    struct CharNode *char_head=NULL;
    struct IntNode *int_temp=NULL;
    struct CharNode *char_temp=NULL;
    int choice;
    int int_val;
    char char_val;
    int c_continue;
    printf("Creating two separate linked lists (one for integers, one for characters):\n");
    while(1){
        printf("Enter data type to add (0 for int, 1 for char): ");
       if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input for data type. Please enter 0 or 1.\n");
            scanf("%*[^\n]");
            scanf("%*c"); 
            continue;
        }
        if(choice==0) { 
            struct IntNode *new_int_node=(struct IntNode*)malloc(sizeof(struct IntNode));
        if (new_int_node==NULL) {
                fprintf(stderr, "Memory allocation for IntNode failed! Exiting.\n");
                exit(EXIT_FAILURE);
            }
            new_int_node->next=NULL;
            printf("Enter integer data: ");
           if (scanf("%d", &new_int_node->data) != 1) {
                fprintf(stderr, "Invalid input for integer data. Skipping this node.\n");
                free(new_int_node);
                scanf("%*[^\n]");
                scanf("%*c");
                continue;
            }
            //scanf("%d",&new_int_node->data);

            if (int_head==NULL) {
                int_head=new_int_node;
                int_temp=new_int_node;
            } else {
                int_temp->next=new_int_node;
                int_temp=new_int_node;
            }
        } 
        else if (choice==1) { 
            struct CharNode *new_char_node=(struct CharNode*)malloc(sizeof(struct CharNode));
           if (new_char_node==NULL) {
                fprintf(stderr, "Memory allocation for CharNode failed! Exiting.\n");
                exit(EXIT_FAILURE);
            }
            new_char_node->next = NULL;
            printf("Enter character data: ");
           if (scanf(" %c", &new_char_node->data) != 1) {
                fprintf(stderr, "Invalid input for character data. Skipping this node.\n");
                free(new_char_node);
                scanf("%*[^\n]");
                scanf("%*c");
                continue;
            }
           // scanf("%d",&new_char_node->data);
            if (char_head==NULL) {
                char_head=new_char_node;
                char_temp=new_char_node;
            } else {
                char_temp->next=new_char_node;
                char_temp=new_char_node;
            }
        } 
        else {
            printf("Invalid type choice. Skipping this input.\n");
           scanf("%*[^\n]");
            scanf("%*c");
            continue;
        }
        printf("Do you want to continue (1 for yes, 0 for no)? ");
        if (scanf("%d", &c_continue) != 1) {
            fprintf(stderr, "Invalid input for continuation. Assuming 'no'.\n");
            scanf("%*[^\n]");
            scanf("%*c");
            break;
        }
       // scanf("%d", &c_continue) ;
        if (c_continue == 0) {
            break;
        }
        scanf("%*[^\n]");
        scanf("%*c"); 
    }
    printf("\nInteger Linked List\n");
    printIntList(int_head);

    printf("\nCharacter Linked List\n");
    printCharList(char_head);
    return 0;
}