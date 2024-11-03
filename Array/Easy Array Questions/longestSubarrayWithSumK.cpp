#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr , int k){
    int n = arr.size();
    int len = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j<n ; j++){
            int sum = 0;
            for(int m = i ; m<=j ; m++){
                sum += arr[m];
            }
            if(sum == k){
                len = max(len , j-i+1);
            }
        }
    }
    return len;
}

int better1(vector<int> arr , int k){
    int len = 0;
    int n = arr.size();
    for(int i = 0 ; i<n; i++){
        int sum = 0;
        for(int j = i ; j<n ; j++){
            sum += arr[j];
            if(sum == k){
                len = max(len , j-i+1);
            }
        }
    }
    return len;
}

int better2(vector<int> arr , int k){
    int n = arr.size();
    map<int , int> preSum;
    int maxlen = 0;
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
        if(sum == k){
            maxlen = max(maxlen , i+1);
        }
        int rem = sum - k;
        if(preSum.find(rem) != preSum.end()){
            int len = i - preSum[rem];
            len = max(len , maxlen);
        }
        if(preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
        }
    }
    return maxlen;
}

int optimal(vector<int> arr , int k){
    int n = arr.size();
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int len = 0;
    while(right < n){
        while(sum > k && left <= right){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            len = max(len , right - left +1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    return len;
}

int main(){
    vector<int> arr = {1,2,1,2,1};
    int k = 3;
    cout<<brute(arr , k)<<endl;
    cout<<better1(arr , k)<<endl;
    cout<<better2(arr , k)<<endl;
    cout<<optimal(arr , k)<<endl;
    return 0;
}