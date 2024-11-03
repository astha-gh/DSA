#include<bits/stdc++.h>
using namespace std;

int brute(int arr[] , int n){
     for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j+1] , arr[j]);
            }
        }
    }
    return arr[n-2];
}

int better(int arr[] , int n){
    int max = arr[0];
    int sec_max = arr[0];
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 0 ; i<n ; i++){
        if((arr[i] > sec_max) && (arr[i] != max)){
            sec_max = arr[i];
        }
    }
    return sec_max;
}

int optimised(int arr[] , int n){
    int max = arr[0];
    int sec_max = arr[0];
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > max){
            sec_max = max;
            max = arr[i];
        }
        else if(arr[i] > sec_max && arr[i] != max){
            sec_max = arr[i];
        }
    }
    return sec_max;
}

int main(){
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Second Largest Element : "<<brute(arr , n)<<endl;
    cout<<"Second Largest Element : "<<better(arr , n)<<endl;
    cout<<"Second Largest Element : "<<optimised(arr , n)<<endl;

    return 0;
}