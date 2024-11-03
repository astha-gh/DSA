#include <bits/stdc++.h>
using namespace std;

int brute(int arr[] , int n){
    int ans = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            int controller = min(arr[i] , arr[j]);
            ans = max(ans , controller*(j-i));
        }
    }
    return ans;
}

int optimal(int height[] , int n){
    int left = 0;
    int right = n-1;
    int ans = 0;
    //Shorter height moves forward or backwards
    while(left < right){
        int width = right - left;
        if(height[left] > height[right]){
            int water = width * height[right];
            ans = max(ans , water);
            right--;
        }
        else{
            int water = width * height[left];
            ans = max(ans , water);
            left++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<brute(arr , n)<<endl;
    cout<<optimal(arr , n)<<endl;
}