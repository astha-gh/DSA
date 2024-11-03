#include <iostream>
using namespace std;

int brute(int arr[] , int n){
     for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j+1] , arr[j]);
            }
        }
    }
    return arr[n-1];
}

int recursive(int arr[] , int n){
    int max = arr[0];
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {2,5,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Largest ELement : "<<recursive(arr , n)<<endl;

    cout<<"Largest Element : "<<brute(arr , n)<<endl;
    return 0;
}