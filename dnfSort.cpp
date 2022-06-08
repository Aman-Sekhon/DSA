#include<bits/stdc++.h>
using namespace std;

void dnfSort(int arr[], int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int32_t main(){
    int arr[] = {1,0,2,1,0,1,2,1,2};
    dnfSort(arr, 9);
    for(int i = 0; i < 9; i++){
        cout << arr[i] <<" ";
    }
    cout<<endl;
    return 0;
}