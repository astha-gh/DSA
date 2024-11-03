/*
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day\
in the future to sell that stock. Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

int brute(int arr[] , int n){
    int profit = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[j] > arr[i]){
                profit = max(profit , arr[j] - arr[i]);
            }
           
        }
    }
    return profit;
}

//DYNAMIC PROGRAMMING
int optimal(int arr[] , int n){
    int profit = 0;
    int min_price = INT_MAX;
    for(int i = 1 ; i<n ; i++){
        // if(min_price > arr[i]){
        //     min_price = arr[i];
        // }
        min_price = min(min_price , arr[i]);
        int ans = arr[i] - min_price;
        profit = max(profit , ans);
    }
    return profit;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<brute(arr , n)<<endl;
    cout<<optimal(arr , n)<<endl;
    
    return 0;
}