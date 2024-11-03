#include <bits/stdc++.h>
using namespace std;

void brute(vector<int> arr , int n){
    // for(int i = 0 ; i<n-1 ; i++){
    //     for(int j = 0 ; j<n-i-1 ; j++){
    //         if(arr[j] > arr[j+1]){
    //             swap(arr[j] , arr[j+1]);
    //         }
    //     }
    // }
    sort(arr.begin() , arr.end());
    for(auto & it : arr){
        cout<<it<<" ";
    }
}

void better(vector<int> arr , int n){
    int count0 = 0 , count1 = 0 , count2 = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    for(int i = 0 ; i<count0 ; i++) arr[i] = 0;
    for(int i = count0 ; i<count0 + count1 ; i++) arr[i] = 1;
    for(int i = count1 + count0 ; i<n ; i++) arr[i] = 2;

    for(auto &it : arr){
        cout<<it<<" ";
    }
}

//DUTCH NATIONAL FLAG
void optimal(vector<int> arr , int n){
    int low = 0 , mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low++ , mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    }

    for(auto &it : arr){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    int n = arr.size();

    brute(arr , n);
    cout<<endl;

    better(arr , n);
    cout<<endl;

    optimal(arr , n);
    cout<<endl;

    return 0;
}