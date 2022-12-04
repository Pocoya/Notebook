#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> cycle;
inline void dfs(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& order, int v) {
    visited[v] = true;
    for(auto u: adj[v]) {
        if(!visited[u]) {
            dfs(adj, visited, order, u);
        } else if(cycle.find(u) == cycle.end()) {
            cout << "IMPOSSIBLE" << '\n';
            exit(0);
        }
    }
    cycle.insert(v);
    order.push_back(v);
}

//faster input handling
inline int get_int() {
    int r = 0, c = getchar();
    while (c != '-' && c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return r;
}

int main() {
    ios::sync_with_stdio(0);   
    cin.tie(0);
    int n, m;
    //cin >> n >> m;
    n = get_int();
    m = get_int();
    vector<vector<int> > adj(n + 1);
    vector<bool> visited(n, false);
    vector<int> order;
    for (int i = 0; i < m; ++i) {
        int u, v;
        //cin >> u >> v;
        u = get_int();
        v = get_int();
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(adj, visited, order, i);
        }
    }

    for (int i = order.size() - 1; i >= 0; --i) {
        cout << order[i] << '\n';
    }
}
