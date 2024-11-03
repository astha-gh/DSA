#include<iostream>
#include <cmath>
#include <math.h>
using namespace std;

//Armstrong Numbers are the numbers having the sum of digits raised to power no. of digits is equal to a given number

int main(){
    int n ;
    cin>>n;
    int original = n;

    int count = 0;
    int temp = n;
	while(temp != 0){
		count++;
		temp = temp/10;
	}

    cout<<count<<endl;

    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        n = n/10;
        sum = sum + pow(digit , count);
        //problem
    }

    cout<<sum<<endl;


    if(original == sum){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}