#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr , int n , int c){

}

int max_distance(vector<int> arr , int n , int c){
    sort(arr.begin() , arr.end());
    int low = 1;
    int high = arr[n-1] - arr[0];
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(isValid(arr , n , c)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = 5;
    int c = 3;

    return 0;
}