#include <bits/stdc++.h>
#include <iostream>     
#include <vector>              

using namespace std; 

void dfs(vector<vector<int> > &adj, int s, bool visited[], int distance[]) {
    visited[s] = true;
    for(auto u: adj[s]) {
        if(!visited[u]) {
            distance[u] = distance[s] + 1;
            dfs(adj, u, visited, distance);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[n];
    int distance[n];
    memset(visited, false, sizeof(visited));
    memset(distance, 0, sizeof(distance));
    dfs(adj, 0, visited, distance);
    for(int i = 0; i < n; i++) {
        cout << distance[i] << '\n';
    }
}