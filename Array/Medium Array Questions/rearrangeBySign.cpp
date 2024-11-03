/*There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative
order of positive and negative elements, you must return an array of alternately positive and negative values.*/

#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> &arr , int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i = 0 ; i<n/2 ; i++){
        arr[2*i] = pos[i];
        arr[(2*i) + 1] = neg[i];
    }
    return arr;
}

vector<int> optimal(vector<int> &arr , int n){
    int posIndex = 0;
    int negIndex = 1;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > 0){
            arr[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            arr[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,-4,-5};
    int n = arr.size();

    brute(arr , n);

    for(auto &it : arr){
        cout<<it<<" ";
    }

    cout<<endl;

    optimal(arr , n);

    for(auto &it : arr){
        cout<<it<<" ";
    }

    return 0;
}