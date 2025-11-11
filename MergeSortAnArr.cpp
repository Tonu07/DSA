#include<iostream>
using namespace std;
void display(int n,int arr[]){
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
void sorting(int arr[],int temp[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int m=left;m<=right;m++)
        arr[m]=temp[m];
}
void mergeSort(int arr[],int brr[],int left,int right){
    if(left>=right)
        return;
    int mid=left+(right-left)/2;
    mergeSort(arr,brr,left,mid);
    mergeSort(arr,brr,mid+1,right);
    sorting(arr,brr,left,mid,right);
}
int main(){
int n;
cout<<"Enter the size of array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int brr[n];
cout<<"Orginal array:"<<endl;
display(n,arr);
mergeSort(arr,brr,0,n-1);
cout<<"Merge sorted array:"<<endl;
display(n,arr);
}
