#include <iostream>
using namespace std;

void brute(int arr[], int n)
{
    int temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}

void optimal(int arr[] , int n){
    int x = arr[0];
    for(int i = 0 ; i<n-1 ; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = x;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    brute(arr, n);
    cout<<"\n";
    optimal(arr , n);

    return 0;
}