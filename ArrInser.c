#include<stdio.h>
int main(){
int arr[],size,pos,num;
scanf("%d",&size);
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
printf("Enter position:");
scanf("%d",&pos);
printf("Enter number:");
scanf("%d",&num);
int i;
for(i=size-1;i>=pos-1;i--){
    arr[i+1]=arr[i];
}
arr[pos-1]=num;
size++;
int uB=50;
if(pos<=0||pos>uB)printf("Invalid Position\n");
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}
