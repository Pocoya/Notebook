#include <bits/stdc++.h>
#include <iostream>     
#include <vector>       
#include <queue>        

using namespace std;    

void BFS(vector<vector<int> >& adj, int s) {
    int n = adj.size();
    queue<int> q;              
    bool visited[n];           
    int distance[n];

    visited[s] = true;         
    distance[s] = 0;            
    q.push(s);                 

    while(!q.empty()) {       
        int v = q.front(); 
        q.pop();                

        for(auto u: adj[v]) {           
            if(!visited[u]) {           
                visited[u] = true;      
                distance[u] = distance[v] + 1;  
                q.push(u);                      
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << "Distance from " << s << " to " << i << " is " << distance[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);                 

    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);   
    for(int i = 0; i < m; ++i) {    
        int u, v;                   
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(adj, 0);
}