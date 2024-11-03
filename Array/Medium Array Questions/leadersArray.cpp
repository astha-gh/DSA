// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> optimised(vector <int> arr){
    int n = arr.size();
    vector<int> ans;
    int max = arr[n-1];
    ans.push_back(max);
    for(int i  = n-2 ; i>=0 ; i--){
        if(arr[i] > max){
            max = arr[i];
            ans.push_back(max);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> ans1 = brute(arr);
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout<<endl;
     vector<int> ans2 = optimised(arr);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    return 0;
}