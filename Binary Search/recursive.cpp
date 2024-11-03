#include <bits/stdc++.h>
using namespace std;

//iterative code is better as space complexity of recursive approach is O(log n) and in iteratuve it is O(1)
int binarySearch(int arr[], int target, int str, int end)
{
    if (str <= end)
    {
        int mid = str + (end - str) / 2;
        if (target < arr[mid])
        {
            return binarySearch(arr, target, str, mid - 1);
        }
        else if (target > arr[mid])
        {
            return binarySearch(arr, target, mid + 1, end);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int res = binarySearch(arr, target, 0, n - 1);
    cout << res << endl;
}