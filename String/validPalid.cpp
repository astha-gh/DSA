#include <bits/stdc++.h>
using namespace std;

bool valid(string str , int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main(){
    string str = "kayak";
    int n = str.length();

    bool ans = valid(str , n);
    cout<<ans<<endl;

    return 0;
}