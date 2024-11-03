// The union of two arrays can be defined as the common and distinct elements in the two arrays.

#include <bits/stdc++.h>
using namespace std;

vector <int> usingMap(int arr1[] , int arr2[] , int n , int m){
    map<int , int> frq;
    vector<int> Union;
    for(int i = 0 ; i<n ; i++){
        frq[arr1[i]]++;
    }
    for(int i = 0 ; i<m ; i++){
        frq[arr2[i]]++;
    }
    for(auto & it : frq){
        Union.push_back(it.first);
    }
    return Union;
}

vector<int> usingSet(int arr1[] ,int arr2[] , int n , int m){
    set<int> s;
    vector<int> Union;
    for(int i = 0 ; i<n ; i++){
        s.insert(arr1[i]);
    }
    for(int i = 0 ; i<m ; i++){
        s.insert(arr2[i]);
    }
    for(auto & it : s){
        Union.push_back(it);
    }
    return Union;
}

vector<int> usingTwoPointers(int arr1[] ,int arr2[] , int n , int m){
    int i = 0;
    int j = 0;
    vector<int> Union;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            if(Union.size() == 0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(Union.size() == 0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            } 
            j++;
        }
    }
    while(i<n){
        if(Union.size() == 0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
        i++;
    }
    while(j<m){
        if(Union.size() == 0 || Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
        } 
        j++;
    }
    return Union;
}

int main()
{
    int n = 4, m = 4;
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {2, 3, 4, 5};

    vector<int> Union1 = usingMap(arr1 , arr2 , n , m);

    for(auto & it  : Union1){
        cout<<it<<" ";
    }

    cout<<endl;

    vector<int> Union2 = usingSet(arr1 , arr2 , n , m);

    for(auto & it  : Union2){
        cout<<it<<" ";
    }

    cout<<endl;

    vector<int> Union3 = usingTwoPointers(arr1 , arr2 , n , m);

    for(auto & it  : Union3){
        cout<<it<<" ";
    }

    return 0;
}