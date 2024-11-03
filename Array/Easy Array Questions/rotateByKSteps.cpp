#include<iostream>
using namespace std;

/*
when k = 1,2,3,4.......easy
k = n.....array is same
when k>n.....use k=k%n
beacuse if size of array is 7 and k = 8 = 7+1
therefore only one step required
*/

void brute(int arr[] , int n , int k){
    k = k % n;
    int temp[k];
    for(int i = 0 ; i<k ; i++){
        temp[i] = arr[i];
    }
    for(int i = 0 ; i<n-k ; i++){
        arr[i] = arr[i+k];
    }
    for(int i = n-k ; i<n ; i++){
        arr[i] = temp[i - (n-k)];
    }
    //printing array
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void reverse(int arr[] ,int start , int end){
    while(start > end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}

void optimised(int arr[] , int n , int k){
    k = k %n;
    //reverse first k elements
    reverse(arr , 0 , k-1);
    //reverse last n-k elements
    reverse(arr , k , n-1);
    //reverse whole array
    reverse(arr , 0 , n-1);


    //printing array
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2 ;
    brute(arr , n, k);
    cout<<endl;
    optimised(arr , n ,k);

    return 0;
}




