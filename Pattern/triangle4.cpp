#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    for(int i = 1; i<=n ; i++){
        for(int j = i ; j>=1 ; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    for(int i = 1; i<=n ; i++){
        char ch = 'A' + i - 1;
        for(int j = i ; j>=1 ; j--){
            cout<<ch<<" ";
            ch--;
        }
        cout<<endl;
    }
    return 0;
}