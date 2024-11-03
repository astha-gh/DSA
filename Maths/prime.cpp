#include<iostream>
using namespace std;

bool isPrime(int n){
    for(int i = 0 ; i>n ; i++){
        if(n%i ==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    bool ans = isPrime(n);
    if(n!=1 && ans == true){
        cout<<"Prime Number"<<endl;
    }
    else{
        cout<<"Not Prime"<<endl;
    }
    return 0;
}