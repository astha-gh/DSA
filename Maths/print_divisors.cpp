#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //Brute for approach
    for(int i = 1 ; i<=n ; i++){
        if(n%i == 0){
            cout<<i<<endl;
        }
    }
    return 0;
}