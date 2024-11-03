/* Given an array of N integers, write a program to return an element that occurs more than N/2 times
in the given array. You may consider that such an element always exists in the array.*/

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return arr[i];
        }
    }
    return -1;
}

int better(vector<int> arr)
{
    map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

int mooreVotingAlgo(vector<int> arr)
{
    int n = arr.size();
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int countele = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            countele++;
        }
    }
    if (countele > n / 2)
    {
        return ele;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << brute(arr) << endl;
    cout << brute(arr) << endl;
    cout << mooreVotingAlgo(arr) << endl;
    return 0;
}