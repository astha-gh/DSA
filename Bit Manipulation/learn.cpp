#include <bits/stdc++.h>
using namespace std;

string reverse(string res){
    int start = 0;
    int end = res.size() - 1;
    while(start < end){
        swap(res[start++] , res[end--]);
    }
    return res;
}

//converting number to binary
string convertToBi(int n){
    string res = "";
    while(n > 0){
        if(n % 2 == 1) res += '1';
        else res += '0';
        n = n / 2;
    }
    reverse(res);
    return res;
}

//converting binary to number
int converttoNum(string bi){
    int num = 0;
    int powTwo = 1;
    for(int i = bi.size() - 1 ; i>=0 ; i--){
        if(bi[i] == '1') num += powTwo;
        powTwo *= 2;
    }
    return num;
    
}

int main(){
    int n = 15;
    string bi = "1111";
    string res = convertToBi(n);
    cout<<res<<endl;
    int num = converttoNum(bi);
    cout<<num<<endl;
    return 0;
}