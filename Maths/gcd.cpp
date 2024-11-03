#include<bits/stdc++.h>
using namespace std;

/*
GCD is the highest common divisor of two numbers
Eg : 9 & 12
9 -> 1,3,9
12 ->1,2,3,4,6,9,12
Common divisor-> 1,3
Highest common divisor/GCD ---> 3
*/


//Brute Force Approch
int gcd(int a , int b){
    int gcd;
    for(int i = 1 ; i<=min(a,b) ; i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }
    return gcd;
}

//Optimal Approach ------> EUCLIDEAN ALGORITHM
/*
It states that if a>b then;
gcd(a , b) == gcd(a-b , b);
Eg :gcd(20 , 15) == gcd(5 , 15);
    gcd(15 , 5) == gcd(10 , 5);
    gcd( 5  , 5) ==  gcd (0 , 5) -----> Once one becomes 0 , the other one is gcd
    therefor gcd is 5.



But for even more optimisation 
gcd(a , b) == gcd(a%b , b)    
*/

int euclien(int a , int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a==0){
        cout<<b<<endl;
    }
    else{
        cout<<a<<endl;
    }
}

int main(){
    cout<<gcd(9 , 12)<<endl;
    euclien(9 ,12);
    return 0;
}