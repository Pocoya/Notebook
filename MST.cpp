#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool compWeight (edge a, edge b) {
    return a.w < b.w;
}

bool compEdges(edge a, edge b) {
    if (a.u == b.u) {
        return a.v < b.v;
    }
    return a.u < b.u;
}

int find(vector<int>& ds, int v) {
    if (ds[v] == v) return v;
    return ds[v] = find(ds, ds[v]);
}

void merge(vector<int>& ds, int u, int v) {
    u = find(ds, u);
    v = find(ds, v);
    
    if(u == v) return;
    if(ds[u] == ds[v]) {
        ds[u] = v;
        ds[v] = v;
    } else if(ds[u] < ds[v]) {
        ds[v] = u;
    } else {
        ds[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(0);   
    cin.tie(0);

    int n, m;
    while(cin >> n && cin >> m && n != 0) {
        vector<edge> edges;
        vector<edge> mst;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            if(u > v) {
                swap(u, v);
            }
            edges.push_back(edge(u, v, w));
        }
        sort(edges.begin(), edges.end(), compWeight);
        vector<int> ds(n + 1);
        for (int i = 0; i < n; ++i) ds[i] = i;
        int weight = 0;
        for (int i = 0; i < m; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (find(ds, u) != find(ds, v)) {
                merge(ds, u, v);
                weight += w;
                mst.push_back(edges[i]);
            }
        }

        if(mst.size() != n-1) {
            cout << "Impossible" << '\n';
        } else {
            cout << weight << '\n';
            sort(mst.begin(), mst.end(), compEdges);
            for (int i = 0; i < mst.size(); ++i) {
                cout << mst[i].u << ' ' << mst[i].v << '\n';
            } 
        }
    }
}
