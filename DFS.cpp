#include <bits/stdc++.h>
#include <iostream>     
#include <vector>              

using namespace std; 

void dfs(vector<vector<int> > &adj, vector<bool>& visited, vector<int>& distance, int s) {
    visited[s] = true;
    for(auto u: adj[s]) {
        if(!visited[u]) {
            distance[u] = distance[s] + 1;
            dfs(adj,visited, distance, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);   
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    dfs(adj, visited, distance, 0);
    for(int i = 0; i < n; i++) {
        cout << distance[i] << '\n';
    }
}