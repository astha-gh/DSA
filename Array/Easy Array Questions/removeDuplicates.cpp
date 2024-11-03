#include<bits/stdc++.h>
using namespace std;

void brute(int arr[] , int n){
    set <int>s;
    for(int i = 0 ; i<n ; i++){
        s.insert(arr[i]);
    }
    int j = 0;
    for(int x : s){
        arr[j] = x;
        j++;
    }
}

void duplicate(int arr[] , int n){
    int i = 0;
    for(int j = 1; j<n-1 ; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    
}

int main(){
    int arr[] = {1,1,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicate(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //1 2 3 2 2 3 3 

    brute(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    //1 2 3 2 2 3 3

    return 0;
}