#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int boards[], int n, int m, int mid){
    int Painters = 1;
    int Sum = 0;

    for(int i = 0; i < n; i++){
        Sum += boards[i];
        if(Sum > mid){
            Sum = boards[i];
            Painters++;
            if(Painters > m){
                return false;
            }
        }
    }
    return true;
}

int PainterProblem(int boards[], int n, int m){
    int Max = 0; 
    int sum = 0;

    for(int i = 0; i < n; i++){
        Max=max(Max, boards[i]);
        sum+=boards[i];
    }

    int start = Max;
    int end = sum;
    int ans = INT_MAX;
    while(start < end){
        int mid = (start + end)/2;
        
        if(isPossible(boards, n, m, mid)){
            ans = min(ans, mid);
            end = mid;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout<<"Minimum time possible: "<<PainterProblem(boards, n, m)<<endl;
    return 0;
}