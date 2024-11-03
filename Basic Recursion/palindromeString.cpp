#include <iostream>
using namespace std;

bool palin(string s){
    int start = 0;
    int end = s.length() - 1;
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}

int main(){
    string str = "ABCDCBA";
    int ans = palin(str);

    if(ans == true){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}