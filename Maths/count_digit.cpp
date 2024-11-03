#include<iostream>
#include<string>
#include "../../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/char_traits.h"
using namespace std;

int variable(int n){
    int digit = 0;

    //O(n)
    while(n>0){
        n = n /10;
        digit++;
    }
    return digit;
}

int string_method(int n){
    //O(1)
    string number =  to_string(n);
    return number.length();
}

int main(){
    int n;
    cin>>n;
    int digit = 0;

    cout<<variable(n)<<endl;
    cout<<string_method(n)<<endl;
    return 0;
}