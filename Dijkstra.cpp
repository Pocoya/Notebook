#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int to;
    int w;
    edge(int to, int w) : to(to), w(w) {}
    bool operator<(const edge &e) const {
        return w > e.w;
    }
};

int dijkstra(vector<vector<edge> > &adj, int s, int t) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<edge> pq;
    dist[s] = 0;
    pq.push(edge(s, 0));

    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if(e.to == t) return e.w;
        if(e.w > dist[e.to]) continue;

        for(auto next : adj[e.to]) {
            if(dist[next.to] > dist[e.to] + next.w) {
                dist[next.to] = dist[e.to] + next.w;
                pq.push(edge(next.to, dist[next.to]));
            }
        }
    }
    return dist[t];
}


int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;    
    vector<vector<edge> > adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(edge(v, w));
    }

    cout << dijkstra(adj, s, t) << '\n';
}