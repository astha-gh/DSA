#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    vector<int> ans = optimal(mat);
    for(auto it : ans){
        cout<<it<<" ";
    }                          

    return 0;
}