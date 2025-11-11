#include<stdio.h>
#include<stdlib.h>
struct inode{
    int data;
    struct inode *next;
};
struct cnode{
    char data;
    struct cnode *next;
};
int main(){
    struct inode *ihead=NULL,*itemp=NULL;
    struct cnode *chead=NULL,*ctemp=NULL;
    int c;
    while(1){
        printf("Do you want to continue (1 or 0):");
        scanf("%d",&c);
        if(c==0){
            break;
        }
        int op;
        printf("Which type of data you want to insert:\n press 0 (for int)\n press 1(for char)\n");
        scanf("%d",&op);
        if(op==0){
            struct inode *newnodei;
            newnodei=(struct inode*)malloc(sizeof(struct inode));
            printf("Enter the integer:");
            int n;
            scanf("%d",&n);
            newnodei->data=n;
            newnodei->next=NULL;
            if(ihead==NULL){
                ihead=itemp=newnodei;
            }
            else{
                itemp->next=newnodei;
                itemp=newnodei;
            }
        }
        else{
            struct cnode *newnodec;
            newnodec=(struct cnode*)malloc(sizeof(struct cnode));
            printf("Enter the character:");
            char ch;
            scanf(" %c",&ch);
            newnodec->data=ch;
            newnodec->next=NULL;
            if(chead==NULL){
                chead=ctemp=newnodec;
            }
            else{
                ctemp->next=newnodec;
                ctemp=newnodec;
            }
        }
    }
    if(ihead!=NULL){
        itemp->next=ihead;
    }
    printf("Your integer Linked list :\n");
    if(ihead==NULL){
        printf("List is empty.\n");
    }
    else{
        itemp=ihead;
        do{
            printf("%d ",itemp->data);
            itemp=itemp->next;
        } while(itemp!=ihead);
        printf("\n");
    }
    if(chead!=NULL){
        ctemp->next=chead;
    }
    printf("Your char Linked list :\n");
    if (chead==NULL){
        printf("List is empty.\n");
    }
    else{
        ctemp=chead;
        do{
            printf("%c ",ctemp->data);
            ctemp=ctemp->next;
        }
        while(ctemp!=chead);
        printf("\n");
    }
    return 0;
}
