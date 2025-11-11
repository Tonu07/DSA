#include<stdio.h>
#include<stdlib.h>
// Define the node structure
struct node{
    int data;
    struct node *ll;
    struct node *rl;
};
// Global head pointer
struct node *h = NULL;
// Function to create and insert a node in BST fashion
void insert(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->ll=NULL;
    newNode->rl=NULL;
    if(h==NULL){
        h=newNode;
        return;
    }
    struct node *current=h;
    struct node *parent=NULL;
    while (current!=NULL){
        parent=current;
        if (x<current->data)
            current=current->ll;
        else
            current=current->rl;
    }
    if(x<parent->data)
        parent->ll=newNode;
    else
        parent->rl=newNode;
}

// Optional: Inorder traversal to verify the tree
void inorder(struct node *root){
    if (root!=NULL){
        inorder(root->ll);
        printf("%d ",root->data);
        inorder(root->rl);
    }
}
//preorder
void preorder(struct node *root){
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->ll);
    preorder(root->rl);
}
int main(){
    int x;
    printf("Enter numbers to insert into the tree (0 to stop):\n");
    while (1) {
        printf("Enter DATA: ");
        scanf("%d", &x);
        if (x == 0)
            break;
        insert(x);
    }
    printf("Inorder traversal of tree:\n");
    inorder(h);
    printf("\nPreorder traversal of tree:\n");
    preorder(h);
    return 0;
}
