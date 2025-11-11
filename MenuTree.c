#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *ll;
    struct node *rl;
};
struct node *h=NULL;
void insert(){
    int x;
    printf("Enter the number=");
    scanf("%d",&x);
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
    while(current!=NULL){
        parent=current;
        if(x<current->data){
            current=current->ll;
        }
        else{
            current=current->rl;
        }
    }
    if(x<parent->data){
        parent->ll=newNode;
    }
    else{
        parent->rl=newNode;
    }
}
void inorder(struct node *root){
    if (root!=NULL){
        inorder(root->ll);
        printf("%d ",root->data);
        inorder(root->rl);
    }
}
// Find minimum node
struct node *findMin(struct node *root){
    while(root->ll!=NULL)
        root=root->ll;
    return root;
}
//deletion of node code
struct node *deleteNode(struct node *root,int x){
    //finding the specific node
    if(root==NULL){
         return root;
    }
    if(x<root->data){
        root->ll=deleteNode(root->ll,x);
    }
    else if(x>root->data){
        root->rl=deleteNode(root->rl,x);
    }
    else{
        //No child
        if(root->ll==NULL&&root->rl==NULL){
            free(root);
            return NULL;
        }
        //One child  //Swaping the child with parent
        else if(root->ll==NULL){
            struct node *temp=root->rl;
            free(root);
            return temp;
        }
        else if(root->rl==NULL){
            struct node *temp=root->ll;
            free(root);
            return temp;
        }
        //Two child
        struct node *temp=findMin(root->rl);
        root->data=temp->data;
        root->rl=deleteNode(root->rl,temp->data);
    }
    return root;
}
int main(){
    int op,x;
    while(1){
        printf(".... MENU....\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder Traversal\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        if(op==4){
            break;
        }
        switch(op){
        case 1:insert();
            break;
        case 2:printf("Enter number to delete: ");
            scanf("%d",&x);
            h=deleteNode(h,x);
            break;
        case 3:printf("Inorder traversal: ");
            inorder(h);
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}