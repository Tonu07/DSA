#include<stdio.h>
int main(){
    int m;
    printf("Enter the size of arr: ");
    scanf("%d",&m);
    int arr[m];
    printf("Enter %d elements of arr (sorted): ",m);
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    int n;
    printf("Enter the size of brr: ");
    scanf("%d",&n);
    int brr[n];
    printf("Enter %d elements of brr (sorted): ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&brr[i]);
    }
    int r[m+n];
    int i=0,j=0,k = 0;
    // Merge both arrays while comparing
    while(i<m&&j<n){
        if(arr[i]<brr[j]){
            r[k++]=arr[i++];
        } 
        else{
            r[k++]=brr[j++];
        }
    }
    while(i<m){
        r[k++]=arr[i++];
    }
    while(j<n){
        r[k++]=brr[j++];
    }
    printf("Merged sorted array:\n");
    for(int x=0;x<m+n;x++){
        printf("%d ",r[x]);
    }
    printf("\n");
    return 0;
}