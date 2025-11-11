#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head1,*newnode1,*temp1,*head2,*newnode2,*temp2;
    head1=NULL;
    head2=NULL;
    struct node *original_head1 = NULL; 
    struct node *original_head2 = NULL;
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
    if(head1!=NULL){
        temp1->next=head1;
        original_head1=head1;
    }

    printf("Linked list 1 traversing:\n");
    if(head1==NULL){
        printf("List is empty.\n");
    }
     else{
        temp1=head1; 
        do {
            printf("%d\n",temp1->data);
            temp1=temp1->next;
        } while(temp1!=head1);
    }
    int c2;
    while(1){
        printf("Do you want to continue(press 0 or 1)?:");
        scanf("%d",&c2);
        if(c2==0){
            break;
        }
        newnode2=(struct node*)malloc(sizeof(struct node));
        if(newnode2 == NULL){
            exit(1);
        }
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
    if(head2 != NULL){
        temp2->next=head2;
        original_head2=head2;
    }
    printf("Linkes list 2 traversing:\n");
    if(head2==NULL){
        printf("List is empty.\n");
    } 
    else {
        temp2=head2; 
        do {
            printf("%d\n",temp2->data);
            temp2=temp2->next;
        } while(temp2!=head2);
    }
    
    struct node *rhead=NULL;
    struct node *rtemp=NULL;
    temp1=original_head1;
    temp2=original_head2;
    int list1_exhausted=(temp1==NULL);
    int list2_exhausted=(temp2==NULL);
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
            if (temp1==original_head1) list1_exhausted = 1;
        }
        else{
            rhead=temp2;
            temp2=temp2->next;
            if (temp2==original_head2)list2_exhausted =1;
        }
        rtemp=rhead;
        while (!list1_exhausted || !list2_exhausted){
            if (list1_exhausted) {
                rtemp->next = temp2;
                rtemp = temp2;
                temp2 = temp2->next;
                if (temp2 == original_head2) list2_exhausted = 1;
            } else if (list2_exhausted) {
                rtemp->next = temp1;
                rtemp = temp1;
                temp1 = temp1->next;
                if (temp1 == original_head1) list1_exhausted = 1;
            } else {
                if(temp1->data<=temp2->data){
                    rtemp->next=temp1;
                    rtemp=temp1;
                    temp1=temp1->next;
                    if (temp1 == original_head1) list1_exhausted = 1;
                }
                else{
                    rtemp->next=temp2;
                    rtemp=temp2;
                    temp2=temp2->next;
                    if (temp2 == original_head2) list2_exhausted = 1;
                }
            }
        }
        if(rhead != NULL){ 
            rtemp->next = rhead;
        }
    }

    printf("Merged Linked List:\n");
    if(rhead==NULL){
        printf("Merged list is empty.\n");
    } 
    else{
        struct node *temp_print_merged=rhead; 
        do {
            printf("%d\n",temp_print_merged->data);
            temp_print_merged = temp_print_merged->next;
        } while(temp_print_merged != rhead);
    }
    if(rhead!=NULL){
        struct node *temp_free=rhead;
        struct node *last_node_free= rhead;
        while(last_node_free->next != rhead){
            last_node_free = last_node_free->next;
        }
        last_node_free->next = NULL; 

        while(temp_free != NULL){
            struct node *next_node_to_free = temp_free->next;
            free(temp_free);
            temp_free = next_node_to_free;
        }
    }
    return 0;
}
