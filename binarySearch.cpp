#include <bits/stdc++.h>
#include <iostream>     
#include <vector>       

using namespace std;
//---------------------------------------------------------------------
//binary search recursively
//---------------------------------------------------------------------
bool helper_func(vector<int>& vec, int x, int left, int right) {
    if(left > right) return false;

    int mid = left + (right - left) / 2;
    if(x == vec[mid]) return true;
    else if(x < vec[mid]) return helper_func(vec, x, left, mid - 1);
    else return helper_func(vec, x, mid + 1, right);
}

bool binary_search(vector<int>& vec, int x) {
    return helper_func(vec, x, 0, vec.size() - 1);
}
//---------------------------------------------------------------------
//binary search iteratively
//---------------------------------------------------------------------
bool binary_iter(vector<int>& vec, int x) {
    int left = 0;
    int right = vec.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(x == vec[mid]) return true;
        else if(x < vec[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}
//---------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    while(n-- > 0) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    cout << (binary_iter(vec, 5) ? "Found it" : "Does not exist") << '\n';
}