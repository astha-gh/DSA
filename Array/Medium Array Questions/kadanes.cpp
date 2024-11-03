/*Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.*/

#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n)
{
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int better(int arr[], int n)
{
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

// KADANE'S ALGO
/*A subarray with a sum less than 0 will always reduce our answer and so
this type of subarray cannot be a part of the subarray with maximum sum*/
int optimal(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

void sumArray(int arr[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0;
    int start_index = -1;
    int end_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start_index = start;
            end_index = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    for (int i = start_index; i <= end_index; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << brute(arr, n) << endl;
    cout << better(arr, n) << endl;
    cout << optimal(arr, n) << endl;
    sumArray(arr , n);
    return 0;
}