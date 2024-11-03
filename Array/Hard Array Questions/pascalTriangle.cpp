#include <bits/stdc++.h>
using namespace std;


//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
int rCc(int row , int col){
    long long res = 1;
    for(int i = 0 ; i<col ; i++){
        res = res * (row - i);
        res = res / (i+1);
    }
    return res;
}

int pascalTriangle(int row , int col){
    int ele = rCc(row-1 , col-1);
    return ele;
}

//Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
void printRowNaive(int row){
    for(int c = 1 ; c<=row ; c++){
        cout<<rCc(row-1 , c-1)<<" ";
    }
}

void printRowOpt(int row){
    long long ans = 1;
    cout<<ans<<" ";
    for(int i = 1 ; i<row ; i++){
        ans = ans * (row - i);
        ans = ans / i;
        cout<<ans<<" ";
    }
}

//Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
vector<vector<int>> brute(int n){
    vector<vector<int>> ans;
    for(int row = 1 ; row<=n ; row++){
        vector<int> temp;
        for(int col = 1 ; col<=row ; col++){
            temp.push_back(rCc(row-1 , col-1));
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<int> generateRow(int n){
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int i = 1; i<n ; i++){
        ans = ans * (n-i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> best(int n){
    vector<vector<int>> ans;
    for(int i = 1 ; i<=n ; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout<<element<<endl;
    printRowNaive(r);
    cout<<endl;
    printRowOpt(r);
    cout<<endl;
    vector<vector<int>> ans = brute(r);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout<<endl;
    vector<vector<int>> ans2 = best(r);
    for (auto it : ans2) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}