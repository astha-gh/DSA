#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr , int k){
    int n = arr.size();
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j<n ; j++){
            int sum = 0;
            for(int k = i ; k<=j ; k++){
                sum += arr[k];
            }
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int better(vector<int> arr , int k){
    int n = arr.size();
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        int sum = 0;
        for(int j = i ; j<n ; j++){
            sum += arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int optimal(vector<int> arr , int k){
    int n = arr.size();
    map<int , int> mpp;
    int preSum = 0;
    int count = 0;
    //very important step
    mpp[0] = 1;
    for(int i = 0 ; i<n ; i++){
        preSum += arr[i];
        int remove = preSum - k;
        //mpp[remove] is the count of the remove value
        count += mpp[remove];
        mpp[preSum] += 1;
    }
    return count;
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int ans1 = brute(arr , k);
    cout<<ans1<<endl;
    int ans2 = better(arr , k);
    cout<<ans2<<endl;
    int ans3 = optimal(arr , k);
    cout<<ans3<<endl;
    
    return 0;
}