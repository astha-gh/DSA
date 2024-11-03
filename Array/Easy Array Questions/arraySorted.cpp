// Check if an Array is Sorted

#include <iostream>
using namespace std;

bool brute(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool optimised(int arr[] , int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
            break;
        }
    }
    return true;
}



int main()
{
    int array1[] = {1 , 2, 3, 4, 5};
    int array2[] = {5, 4, 6, 7, 8};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    cout << "Is array sorted : " << brute(array1, n1) << endl;
    cout << "Is array sorted : " << brute(array2, n2) << endl;

    cout << "Is array sorted : " << optimised(array1, n1) << endl;
    cout << "Is array sorted : " << optimised(array2, n2) << endl;


}