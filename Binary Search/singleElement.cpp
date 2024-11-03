//You are given a sorted array consisting of only integers where every element appears
// exactly twice, except for one element which appears exactly once.

#include <bits/stdc++.h>
using namespace std;

int singleELe(int arr[] , int n){
    if(n == 1) return 0;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){
            return mid;
        }
        if(mid == 0 && arr[0] != arr[1]) return mid;
        if(mid == n-1 && arr[n-1] != arr[n-2]) return mid;
        if(mid % 2 == 0){
            if(arr[mid] == arr[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(arr[mid] == arr[mid + 1]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4,8,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = singleELe(arr , n);
    cout<<res<<endl;

    return 0;
}