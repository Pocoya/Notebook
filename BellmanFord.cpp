#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

struct edge {
    int cur, next, w;
    edge(int cur, int next, int w) : cur(cur), next(next), w(w) {}
};

vector<int> bellmanFord(vector<edge>& edges, int s, int n) {
    vector<int> distance(n, INF);
    distance[s] = 0;

    for(int i = 0; i < n - 1; ++i) {
        for(auto e: edges) {
            int a = e.cur;
            int b = e.next;
            int w = e.w;
            if(distance[a] != INF && distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
            }
        }
    }
    //To detect negative cycles
    for(int i = 0; i < n; ++i) {
        for(auto e: edges) {
            int a = e.cur;
            int b = e.next;
            int w = e.w;
            if(distance[a] != INF && distance[a] + w < distance[b]) {
                distance[b] = -INF;
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
        vector<edge> edges;
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(edge(u, v, w));
        }

        vector<int> distance = bellmanFord(edges, s, n);
        for(int i = 0; i < q; ++i) {
            int t;
            cin >> t;
            if(distance[t] == INF) cout << "Impossible" <<'\n';
            else if(distance[t] == -INF) cout << "-Infinity" <<'\n';
            else cout << distance[t] <<'\n';
        }
        cout <<'\n';
    }
}

//g++ -std=c++17 BellmanFord.cpp -o bellmanFord