#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> col;
bool bipartite;

void color(int idx, int curr){
    if(col[idx] != -1 && col[idx] != curr){
        bipartite = false;
        return;
    }
    col[idx] = curr;
    if(visited[idx]){
        return;
    }
    visited[idx] = true;

    for(auto i: adj[idx]){
        color(i, curr xor 1);
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, false);
    col = vector<int> (n, -1);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            color(i, 0);
        }
    }

    if(bipartite){
        cout << "Graph is bipartite." << endl;
    } else {
        cout << "Graph is not bipartite." << endl;
    }
    return 0;
}