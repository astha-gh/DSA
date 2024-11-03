#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = { 1, 2, 3 , 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int query;
    // cin>>query;
    int hash[12] = {0};
    for(int i = 0 ; i<n ; i++){
        hash[arr[i]] += 1;
    }
    cout<<hash[3];
    
    return 0;
}