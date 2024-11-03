#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> arr , int num){
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

int brute(vector<int> arr){
    int n = arr.size();
    int longest = 1;
    for(int i = 0 ; i<n ; i++){
        int x = arr[i];
        int count = 1;
        while(linearSearch(arr , x+1) == true){
            x += 1;
            count++;
        }
        longest = max(longest , count);
    }
    return longest;
    
}

int better(vector<int> arr){
    int n = arr.size();
    sort(arr.begin() , arr.end());
    int count = 0;
    int lastSmaller = INT_MIN;
    int longest = 1;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] - 1 == lastSmaller){  // lastSmaller---> last element is 1 lesser tham the current element
            count += 1;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest , count);
    }
    return longest;
}

int best(vector<int> arr){
    int n = arr.size();
    int longest = 1;
    if(n == 0) return 0;
    unordered_set<int> st;
    for(int i = 0 ; i<n ; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int x = it;
            int count = 1;
            while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
            longest = max(longest , count);
        }
    }
    return longest;
}

int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans1 = brute(a);
    cout<<ans1<<endl;
    int ans2 = better(a);
    cout<<ans2<<endl;
    int ans3 = best(a);
    cout<<ans3<<endl;
    return 0;
}