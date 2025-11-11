#include <iostream>
using namespace std;
// Recursive function to get nth Fibonacci number
int fibonacci(int n) {
    if (n<=1)
        return n; // Base cases: fib(0) = 0, fib(1) = 1
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci Series: ";
    for(int i=0;i<n;i++){
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
    return 0;
}