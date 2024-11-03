#include <bits/stdc++.h>
using namespace std;

string reverse(string str){
    reverse(str.begin() , str.end());
    int n = str.length();
    string ans = "";
    for(int i = 0 ; i<n ; i++){
        string word = "";
        while(str[i] != ' ' && i<n){
            word += str[i];
            i++;
        }
        reverse(word.begin() , word.end());
        if(word.length() > 0){
            ans += ' ' + word;
        }
    }
    return ans.substr(1);
}

int main(){
    string str = "the sky is blue";
    string ans = reverse(str);
    cout<<ans<<endl;
    return 0;
}