#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//find with path compression
inline int find(vector<int>& ds, int v) {
    if (ds[v] == v) return v;
    return ds[v] = find(ds, ds[v]);
}

inline void merge(vector<int>& ds, int u, int v) {
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

//faster input handling
inline int get_int() {
    int r = 0, c = getchar();
    while (c != '-' && c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);

    int n, m;
    n = get_int();
    m = get_int();
    vector<int> ds(n);
    iota(ds.begin(), ds.end(), 0);

    while(m-- > 0) {
        char c;
        int a, b;
        c = getchar();
        a = get_int();
        b = get_int();
        
        if(c == '?') {
            cout << (find(ds, a) == find(ds, b) ? "yes" : "no") << '\n';
        } else {
            merge(ds, a, b);
        }
    }
}
