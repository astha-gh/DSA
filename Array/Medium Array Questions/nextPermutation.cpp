/*Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically
next greater permutation of numbers. If such an arrangement is not possible, it must rearrange
to the lowest possible order (i.e., sorted in ascending order).*/

#include <bits/stdc++.h>
using namespace std;

void better(vector<int> arr)
{
    next_permutation(arr.begin(), arr.end());
    cout << arr[0] << " " << arr[1] << " " << arr[2];
}

vector<int> optimal(vector<int> &arr)
{
    int n = arr.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else
    {
        for (int i = n - 1; i > ind; i--)
        {
            if (arr[i] > arr[ind])
            {
                swap(arr[i], arr[ind]);
                break;
            }
        }
        reverse(arr.begin() + ind + 1, arr.end());
    }
    return arr;
}


int main()
{
    vector<int> arr = {3, 2, 1};
    better(arr);
    cout << endl;
    optimal(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}