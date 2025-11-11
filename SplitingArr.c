#include<stdio.h>
int main(){
int n;
printf("Enter the size of array :");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int oi=0,ei=0;
int odd[n],even[n];
for(int i=0;i<n;i++){
    if(arr[i]%2==0){
even[ei]=arr[i];
ei++;
    }
    else {
        odd[oi]=arr[i];
    oi++;

    }
}
for(int i=0;i<ei;i++){
    printf("%d ",even[i]);
}
printf("\n");
for(int i=0;i<oi;i++){
    printf("%d ",odd[i]);
}
return 0;
}
