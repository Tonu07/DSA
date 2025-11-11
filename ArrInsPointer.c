#include<stdio.h>
#include<stdlib.h>
int main(){
int *p;
int size,pos,num;
printf("Size of array :");
scanf("%d",&size);
p=(int*)malloc(size*sizeof(int));
for(int i=0;i<size;i++){
    scanf("%d",p+i);
}
printf("Enter position:");
scanf("%d",&pos);
printf("Enter number:");
scanf("%d",&num);
int i;
for(i=size-1;i>=pos-1;i--){
    *(p+i+1)=*(p+i);
}
p[pos-1]=num;
size++;
int uB=50;
if(pos<=0||pos>uB)printf("Invalid Position\n");
for(int i=0;i<size;i++){
    printf("%d ",p[i]);
}
}
