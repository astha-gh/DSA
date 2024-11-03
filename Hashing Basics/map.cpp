#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = { 1, 2, 3 , 1, 4, 77, 88, 6,5 ,4 , 4, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int query;
    // cin>>query;
    map<int , int>mpp;
    for(int i = 0 ; i< n ; i++){
        mpp[arr[i]]++;
    }
    //cout<<mpp[query]<<endl;
    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}