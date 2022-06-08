#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladders, snakes;
    cin >> ladders;
    map<int,int> lad;
    map<int,int> snak;
    for(int i=0; i<ladders; i++){
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }
    cin >> snakes;
    for(int i=0; i<snakes; i++){
        int u, v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found  = false;
    vector<bool> visited(101, 0);
    visited[1] = true;
    while(!q.empty() && !found){
        int size = q.size();
        while(size--){
            int t = q.front();
            q.pop();
            for(int die=1; die<=6; die++){
                if(t+die == 100){
                    found = true;
                }
                if(t+die <= 100 && lad[t+die] && !visited[lad[t+die]]){
                    visited[lad[t+die]] = true;
                    if(lad[t+die] == 100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 && snak[t+die] && !visited[snak[t+die]]){
                    visited[snal[t+die]] = true;
                    if(snak[t+die] == 100){
                        found = true;
                    }
                    q.push(snak[t+die]);
                }
                else if(t+die <= 100 && !visited[t+die] && !snak[t+die] && !lad[t+die]){
                    visited[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }

    if(found){
        cout << moves << endl;
    } else{
        cout << "-1" << endl;
    }
    return 0;
}