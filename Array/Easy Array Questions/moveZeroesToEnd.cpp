#include <bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> arr , int n){
    vector<int> temp;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    int noOfNonZero = temp.size();
    for(int i = 0 ; i<noOfNonZero ; i++){
        arr[i] = temp[i];
    }
    for(int i = noOfNonZero ; i<n ; i++){
        arr[i] = 0;
    }
    return arr;
}

vector<int> optimised(vector<int> arr , int n){
    int j = -1;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j== -1){
        return arr;
    }

    for(int i = j+1 ; i<n ; i++){
        if(arr[i] != 0){
            swap(arr[i] , arr[j]);
            j++;
        }
    }
    return arr;
}



int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;

    vector<int> ans1 = brute(arr , n);
    for (auto &it : ans1) {
        cout << it << " ";
    }
    cout << '\n';

    vector<int> ans2 = optimised(arr, n);
    for (auto &it : ans2) {
        cout << it << " ";
    }

    return 0;
}