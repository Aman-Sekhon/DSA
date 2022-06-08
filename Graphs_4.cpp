#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        // x->y
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int p = q.front();
        q.pop();
        cout << p << " ";

        for(auto it: adj[p]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    return 0;
}