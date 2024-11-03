#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "ababsdraabs";
    int n = str.size();
    // char query;
    // cin>>query;
    int hash[260] = {0};
    for(int i = 0 ; i<n ; i++){
        hash[str[i]] += 1;
    }
    cout<<hash['a']<<endl;
    return 0;
}