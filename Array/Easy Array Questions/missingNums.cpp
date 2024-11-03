#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
    return -1;
}

int better(int arr[], int n){
    int hash[n+1] = {0};
    for(int i = 0 ; i<n ; i++){
        hash[arr[i]]++;
    }
    for(int i = 1 ; i<=n ; i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;
}

int optimal1(int arr[], int n){
    int sum1 = (n*(n+1))/2;
    int sum2 = 0;
    for(int i = 0 ; i<n-1 ; i++){
        sum2 += arr[i];
    }
    int miss = sum1 - sum2;
    return miss;
}

int optimal2(int arr[], int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0 ; i<n-1 ; i++){
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}


int main()
{
    int array1[] = {1, 2, 3, 5};
    int n1 = sizeof(array1) / sizeof(array1[0]);

    cout << brute(array1, n1) << endl;
    cout << better(array1, n1) << endl;
    cout << optimal1(array1, n1) << endl;
    cout << optimal2(array1, n1) << endl;


    return 0;
}