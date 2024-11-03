// Remove all occurrences of a substring
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"

//use str.find() and str.erase()

#include <bits/stdc++.h>
using namespace std;

string removed(string str , string part){
    while(str.length() > 0 && str.find(part) < str.length()){
        str.erase(str.find(part) , part.length());
    }
    return str;
}

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";

    string ans = removed(str , part);
    cout<<ans<<endl;
    return 0;
}