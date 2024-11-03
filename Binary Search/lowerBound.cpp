#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr , int n , int x){
    int low = 0;
    int high = n-1;
    //Hypothetical next index in case there is no answer
    int res = n;
    while (low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= x){
            res = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1 ,2, 8, 10, 11, 12, 19};
    int n = 7, x = 0;
    int ans = lowerBound(arr, n, x);
    cout<<ans<<endl;
    return 0;
}