 #include <stdio.h>
int main() {
    int n;
    printf("Enter the array number:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
      int x,j;
    for(int i=1;i<n;i++){
        x=arr[i];      
        j=i-1;
        while(j>=0&&arr[j]>x){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
    printf("Sorted array:   ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}