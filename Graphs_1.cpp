#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e5+2;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    
    return 0;
}