
#include<bits/stdc++.h>
using namespace std;


void print(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void simple(int arr[], int n) {
    int ans[n];
    for (int i = n - 1; i >= 0; i--) {
      ans[n-i-1] = arr[i];
    }
    print(ans , n);
}

void pointer(int arr[] , int n){
    int p1 = 0;
    int p2 = n-1;
    while(p1 < p2){
        swap(arr[p1++] , arr[p2--]);
    }
    print(arr , n);
}



int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    simple(arr , n);
    cout<<"\n"; 
    pointer(arr , n);
    cout<<"\n"; 
    //I dont know why recursive method is not working
    

    return 0;
}


