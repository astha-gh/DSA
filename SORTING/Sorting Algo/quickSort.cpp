#include <iostream>
using namespace std;

int partition(int arr[] , int low , int high){
    int pivot = arr[low];
    int i = low ;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[low] , arr[j]);
    return j;
}

void quickSort(int arr[] , int low , int high){
    if(low < high){
        int j = partition(arr , low , high);
        quickSort(arr , low , j-1);
        quickSort(arr , j+1 , high);
    }
}

int main(){
    int arr[] = {4,1,7,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr , 0 , n-1);

    for(int i = 0 ; i< n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}