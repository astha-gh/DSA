#include<iostream>
using namespace std;

int linear(int arr[] , int n , int num){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<linear(arr , n , 7);
    return 0;
}