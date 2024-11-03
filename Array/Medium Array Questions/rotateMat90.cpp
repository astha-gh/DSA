#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> matrix , int n){
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            ans[j][n-i-1] = matrix[i][j];
        }
    }
    return ans;
}

vector<vector<int>> best(vector<vector<int>> matrix , int n){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<i ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }
    for(int i = 0 ; i<n ; i++){
        reverse(matrix[i].begin() , matrix[i].end());
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();

    vector<vector<int>> ans1 = brute(matrix , n);
    for(auto it : ans1){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> ans2 = best(matrix , n);
    for(auto it : ans2){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}