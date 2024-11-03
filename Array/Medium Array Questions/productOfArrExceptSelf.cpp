#include <bits/stdc++.h>
using namespace std;

//If division operator not allowed, you cannot use this method
void division(vector<int> arr){
    int n = arr.size();
    int prod = 1;
    for(int i = 0 ; i<n ; i++){
        prod *= arr[i];
    }
    for(int i = 0 ; i<n ; i++){
        arr[i] = prod / arr[i];
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
}

vector<int> brute(vector<int> &arr , int n){
    vector<int> ans(n , 1);
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j<n ; j++){
            if(i != j){
                ans[i] *= arr[j];
            }
        }
    }
    return ans;
}

vector<int> better(vector<int> arr , int n){
    vector<int> ans(n , 1);
    vector<int> prefix(n, 1);
    for(int i = 1 ; i<n ; i++){
        prefix[i] = prefix[i-1] * arr[i-1];
    }
    vector<int> suffix(n , 1);
    for(int i = n-2 ; i>=0 ; i--){
        suffix[i] = suffix[i+1] * arr[i+1];
    }
    for(int i = 0 ; i<n ; i++){
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

vector<int> optimal(vector<int> arr , int n){
    vector<int> ans(n , 1);
    for(int i = 1 ; i<n ; i++){
        ans[i] = ans[i-1] * arr[i-1];
    }
    int suffix = 1;
    for(int i = n-2 ; i>=0 ; i--){
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int n = arr.size();

    vector<int> res1 = brute(arr , n);
    for(int ele : res1){
        cout<<ele<<" ";
    }
    cout<<endl;

    vector<int> res2 = better(arr , n);
    for(int ele : res2){
        cout<<ele<<" ";
    }
    cout<<endl;

    vector<int> res3 = optimal(arr , n);
    for(int ele : res3){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}