#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[] , int n , int m , int mid){
    int stu = 1;
    int pages = 0;
    int allowedPages = mid;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > allowedPages){
            return false;
        }
        if(pages + arr[i] <= allowedPages){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }

    if(stu <= m){
        return true;
    }
    else{
        return false;
    }
}

int minPages(int arr[] , int n , int m){
    if(n < m) return -1;
    int sum =  0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
    }
    int low = 0;
    int high = sum;
    int res = -1;
    while (low <= high){
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
    int arr[] = {15 , 17 , 20};
    int n = 3;
    int m = 2;

    cout<<minPages(arr , n , m)<<endl;

    return 0;
}