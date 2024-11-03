#include <bits/stdc++.h>
using namespace std;

vector<int> sort2array(vector<int> a , vector<int> b , int m , int n){
    int idx = m+n-1 , i = m-1, j = n-1;
    while(i>=0 && j>=0){
        if(a[i] >= b[j]){
            a[idx] = a[i];
            idx--, i--;
        }
        else{
            a[idx] = b[j];
            idx--, j--;
        }
    }
    while(j>=0){
        a[idx] = b[j];
        idx--, j--;
    }
    return a;
}

int main(){
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    int m = 3;     //valid elements of the array
    int n = 3;

    vector<int> ans = sort2array(a , b , m , n);
    for(int i = 0 ; i<a.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}