#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] , int n , int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;

    int res = binarySearch(arr , n , target);
    cout<<res<<endl;

    return 0;
}