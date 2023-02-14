#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

struct edge {
    int node, w;
    edge(int node, int w) : node(node), w(w) {}

    bool operator<(const edge& e) const {
        return e.w < w;
    }
};

vector<int> dijkstra(vector<vector<edge> >& adj, int s) {
    priority_queue<edge> pq;
    vector<int> distance(adj.size(), INF);
    pq.push({s, 0}); 
    distance[s] = 0;

    while(!pq.empty()) {
        edge cur = pq.top();
        pq.pop();

        if(distance[cur.node] < cur.w) continue;
        for(auto next: adj[cur.node]) {
            if(distance[cur.node] + next.w < distance[next.node]) {
                distance[next.node] = distance[cur.node] + next.w;
                pq.push({next.node, distance[next.node]});
            }
        }
    }
    return distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, s;
    while(cin >> n >> m >> q >> s && n != 0) {
        vector<vector<edge> > adj(n);
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(edge(v, w));
        }

        vector<int> distance = dijkstra(adj, s);
        for(int j = 0; j < q; ++j) {
            int t;
            cin >> t;
            if(distance[t] == INF) cout << "Impossible\n" <<'\n';
            else cout << distance[t]<<'\n';
        }
    }
}

//g++ -std=c++17 Dijkstra.cpp -o dijkstra
