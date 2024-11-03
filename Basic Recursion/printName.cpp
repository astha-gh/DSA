#include<iostream>
using namespace std;

//phenomenon when a function calls itself indefinitely until a specified condition is fulfilled.

int count = 0;
int name(){
    if(count == 5){
        return 0;
    }
    cout<<"Luffy"<<endl;
    count++;
    name();
}

int main(){
    //Print luffy n times;

    name();

    return 0;
}