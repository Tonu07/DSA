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
struct inode *ihead,*itemp;
struct cnode *chead,*ctemp;
ihead=NULL;
chead=NULL;
int c;
while(1){
    printf("Do you want to continue (1 or 0):");
    scanf("%d",&c);
    if(c==0){
        break;
    }
    int op;
    printf("Whice type of data you want to insert:\n press 0 (for int)\n press 1(for char)\n");
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
    printf("Enter the charecter:");
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
printf("Your integer Linked list :\n");
itemp=ihead;
while(itemp!=NULL){
    printf("%d ",itemp->data);
    itemp=itemp->next;
}
printf("\n");
printf("Your char Linked list :\n");
ctemp=chead;
while(ctemp!=NULL){
    printf("%c ",ctemp->data);
    ctemp=ctemp->next;
}
printf("\n");
}
