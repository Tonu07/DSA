#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,5,3,2};
    v.push_back(8);
    v.push_back(7);
    for(int i:v){
        cout<<i<<" ";
}
cout<<endl;
sort(v.begin(),v.end());
cout<<"After Sorting:"<<endl;
  for(int i:v){
        cout<<i<<" ";
}
}
