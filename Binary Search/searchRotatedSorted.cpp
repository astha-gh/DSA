#include <bits/stdc++.h>
using namespace std;

int RotatedSortedArray(int arr[] , int n , int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return mid;
        }
        //left side sorted
        if(arr[low] <= arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        //right side sorted
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 0;

    int res = RotatedSortedArray(arr , n , target);
    cout<<res<<endl;

    return 0;
}