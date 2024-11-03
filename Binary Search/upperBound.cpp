#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr , int n , int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ans = upperBound(arr, n, x);
    cout << ans << endl;
    return 0;
}