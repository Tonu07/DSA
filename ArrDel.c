#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of array :");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int pos;
printf("Enter the position you want to delete:");
scanf("%d",&pos);
for(int i=pos-1;i<n-1;i++){
    arr[i]=arr[i+1];
}
n--;
for(int i=0;i<n;i++){
 printf("%d ",arr[i]);
}
return 0;
}
