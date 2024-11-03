#include <iostream>
using namespace std;

void merge(int arr[] , int low , int mid , int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];

    for(int i = 0 ; i < n1 ; i++){
        left[i] = arr[low + i];
    }

    for(int j = 0 ; j< n2 ; j++){
        right[j] = arr[mid + 1 + j];
    }

    int i = 0 , j = 0 , k = low;
    while(i<n1 && j<n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    while(i<n1){
        arr[k++] = left[i++];
    }
    while(j<n2){
        arr[k++] = right[j++];
    }
}

void mergerSort(int arr[] , int low , int high){
    if(low >= high){
        return;
    }
    int mid = (low + high) / 2;
    mergerSort(arr , low , mid);
    mergerSort(arr , mid+1 , high);
    merge(arr , low , mid , high);
}

int main(){
    int arr[] = {4,2,1,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergerSort(arr , 0 , n-1);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    
}