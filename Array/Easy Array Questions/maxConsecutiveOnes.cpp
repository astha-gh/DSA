#include <bits/stdc++.h>
using namespace std;

int maxOnes(vector<int> &arr){
    int count = 0;
    int max_count = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] == 1){
            count++;
        }
        else{
            count = 0;
        }
        max_count = max(count , max_count);
    }
    return max_count;
}

int main(){
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    cout<<maxOnes(nums)<<endl;

    return 0;
}