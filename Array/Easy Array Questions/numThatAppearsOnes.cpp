#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                flag++;
            }
        }
        if (flag == 1)
        {
            return num;
        }
    }
    return -1;
}

int betterHash(vector<int> &arr)
{
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
    return -1;

    // int hash[arr.size() + 1] = {0};
    // for(int i = 0 ; i<arr.size() ; i++){
    //     hash[arr[i]]++;
    // } 
    // for(int i = 0 ; i<arr.size() ; i++){
    //     if(hash[arr[i]] == 1){
    //         return arr[i];
    //     }
    // }
    // return -1;
}

int betterMap(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto &it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

int optimal(vector<int> &arr){
    int n = arr.size();
    int x = 0;
    for(int i = 0 ; i<n ; i++){
        x = x ^ arr[i];
    }
    return x;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = brute(arr);
    cout << ans << endl;
    cout << betterHash(arr) << endl;
    cout << betterMap(arr) << endl;
    cout << optimal(arr) << endl;
}