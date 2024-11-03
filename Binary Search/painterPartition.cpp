#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[] , int n , int m , int mid){
    int painter = 1;
    int time = 0;
    int allowedTime = mid;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > allowedTime){
            return false;
        }
        if(time + arr[i] <= allowedTime){
            time += arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
    }
    if(painter > m){
        return false;
    }
    else{
        return true;
    }
}

int minTime(int arr[] , int n , int m){
    if(n < m) return false;
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
    }
    int low =  0;
    int high = sum;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(isValid(arr , n , m , mid)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int arr[] = {40 , 30 , 10 , 20};
    int n = 4;
    int m = 2;

    cout<<minTime(arr , n, m)<<endl;

    return 0;
}