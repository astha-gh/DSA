/*Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and
then return the matrix.*/

#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix , int n , int m , int i){
    for(int j = 0 ; j<m ; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix , int n , int m , int j){
    for(int i = 0 ; i<n ; i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> brute(vector<vector<int>> &matrix , int n , int m){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j] == 0){
                markRow(matrix , n , m, i);
                markCol(matrix , n , m ,j);
            }
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

vector<vector<int>> better(vector<vector<int>> &matrix , int n , int m){
    int row[n] = {0};
    int col[m] = {0};
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(row[i] || col[j]){
                matrix[i][j] == 0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans1 = brute(matrix , n , m);
    for(auto it : ans1){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    cout<<"\nBetter : \n"<<endl;

    vector<vector<int>> ans2 = better(matrix , n , m);
    for(auto it : ans2){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    
    
    return 0;
}