#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
struct node *create(){
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
int x;
printf("Enter the data (0 for close):");
scanf("%d",&x);
if(x==0){
    return NULL;
}
newnode->data=x;
printf("Enter the left child of %d\n",x);
newnode->left=create();
printf("Enter the right child of %d\n",x);
newnode->right=create();
return newnode;

}
void preorder(struct node*root){
    if (root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
struct node *root;
root=create();
printf("Preorder Traversal:");
preorder(root);
printf("\n");
return 0;
}