#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
int n, m;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx){
    if(visited[idx])
        return 0;

    visited[idx] = true;
    int ans = 1;
    for(auto i: adj[idx]){
        if(!visited[i]){
            ans += get_comp(i);
            visited[i] = true;
        }
    }
    return ans;
}

int32_t main(){
    cin >> n >> m;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n);

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            components.push_back(get_comp(i));
        }
    }

    // for(auto i: components){
    //     cout << i << "  ";
    // }

    long long ans = 0;
    for(auto i: components){
        ans += i*(n-i);
    }
    cout << (ans/2) << endl;
    return 0;
}