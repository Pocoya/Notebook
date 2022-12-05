#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

//faster input handling
inline ll get_int() {
    ll r = 0, c = getchar(), s = 1;
    while (c != '-' && c < '0' || c > '9') c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}

ll sum(vector<ll>& fenwick, int i){
    ll s = 0;
    while(i > 0){
        s += fenwick[i];
        i -= i & -i;
    }
    return s;
}

void add(vector<ll>& fenwick, int i, int val){
    i++;
    while(i < fenwick.size()){
        fenwick[i] += val;
        i += i & -i;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, q;
    n = get_int();
    q = get_int();
    vector<ll> vec(n + 1, 0);
    for(int k = 0; k < q; ++k) {
        char c;
        c = getchar();
        int i;
        ll val;
        if(c == '+') {
            i = get_int();
            val = get_int();
            add(vec, i, val);
        } else {
            i = get_int();
            cout << sum(vec, i)<< '\n';
        }
    }
}