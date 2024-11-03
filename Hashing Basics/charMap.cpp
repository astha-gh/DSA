#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "ababsdraabsf";
    int n = str.size();
    map<char , int>mpp;
    for(int i = 0 ; i<n ; i++){
        mpp[str[i] - 'a']++;
    }
    cout<<mpp['f' - 'a']<<endl;
    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}