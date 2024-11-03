#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int num = 1;
    char ch = 'A';
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }

    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    return 0;
}