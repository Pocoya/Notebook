#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

//faster input handling
inline ll get_int() {
    ll r = 0, c = getchar();
    while (c != '-' && c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return r;
}

inline ll sum(vector<ll>& fenwick, ll i){
    ll s = 0;
    while(i > 0){
        s += fenwick[i];
        i -= i & -i;
    }
    return s;
}

inline void add(vector<ll>& fenwick, ll i, ll val){
    while(i <= (ll)fenwick.size()){
        fenwick[i] += val;
        i += i & -i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n = get_int();
    vector<ll> fenwick(n + 2);
    vector<pair<ll, ll> > pairs;
    for(ll i = 1; i <= n; ++i){
        pairs.push_back(make_pair(get_int(), i));
    }

    sort(pairs.begin(), pairs.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first > b.first;
    });

    ll inversions = 0;
    for(pair<ll, ll> p: pairs) {
        inversions += sum(fenwick, p.second);
        add(fenwick, p.second, 1);
    }
    cout << inversions << '\n';
}
