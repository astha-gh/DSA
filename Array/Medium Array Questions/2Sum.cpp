#include <bits/stdc++.h>
using namespace std;

string brute(vector <int> arr , int target){
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        for(int j = i + 1 ; j<n ; j++){
            if(arr[i] + arr[j] == target){
                return "YES";
            }
        }
    }
    return "NO";
}

string better(vector<int> arr , int target){
    int n = arr.size();
    unordered_map<int , int> mpp;
    for(int i = 0 ; i<n ; i++){
        int num = arr[i];
        int moreNeeded = target - arr[i];
        if(mpp.find(moreNeeded) != mpp.end()){
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}

string best(vector <int> arr , int target){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum < target){
            left++;
        }
        else if(sum > target){
            right--;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}

int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 8;
    string ans1 = brute(arr, target);
    cout << "This is the answer for variant 1: " << ans1 << endl;
    string ans2 = better(arr, target);
    cout << "This is the answer for variant 2: " << ans2 << endl;
    string ans3 = best(arr, target);
    cout << "This is the answer for variant 3: " << ans3 << endl;
    return 0;
}