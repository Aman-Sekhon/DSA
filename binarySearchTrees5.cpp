#include<iostream>
using namespace std;

int findPeakElement(int arr[], int n, int left, int right){
    int mid = left + (right-left)/2;

    if((mid == n-1 || arr[mid+1] <= arr[mid]) && (mid == 0 || arr[mid-1]<=arr[mid])){
        return mid;
    }

    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr, n, left, mid-1);
    }
    
    else{
        return findPeakElement(arr, n, mid+1, right);
    }
}

int main(){
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;
    cout<<"The index of Peak Element is: "<<findPeakElement(arr, n, 0, n-1)<<endl;
    return 0;
}