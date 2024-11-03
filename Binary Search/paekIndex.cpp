#include <bits/stdc++.h>
using namespace std;

int peakEle(int arr[] , int n){
    int low = 1;
    int end = n-2;
    while(low <= end){
        int mid = low + (end - low)/2;
        if(arr[mid] > arr[mid+1] && arr[mid]> arr[mid-1]){
            return mid;
        }
        if(arr[mid] > arr[mid - 1]){
            low = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {0,10,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = peakEle(arr , n );
    cout<<res<<endl;
    
    return 0;
}