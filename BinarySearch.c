#include<stdio.h>
int main(){
int n;
printf("Enter the size of array :");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int target;
printf("Enter the value you want to find:");
scanf("%d",&target);
int lb=0,ub=n-1;
int mid;
for(int i=0;lb<=ub;i++){
        mid=(lb+ub)/2;
    if(arr[mid]==target){
            printf("The position=%d",mid+1);
    break;
    }
    else if(arr[mid]<target){
        lb=mid+1;
    }
    else{
        ub=mid-1;
    }

}
}
