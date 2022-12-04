#include <bits/stdc++.h>
#include <iostream>     
#include <vector>       
#include <math.h>        

using namespace std; 

//-----------------------------------------
// Typical DP problem
//-----------------------------------------
int maxSum(vector<vector<int> >& grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<int> > sum(H, vector<int>(W));
    for(int row = 0; row < H; ++row) {
        for(int col = 0; col < W; ++col) {
            if(row == 0 && col == 0) sum[row][col] = grid[row][col];
            else if(row == 0) sum[row][col] = sum[row][col-1] + grid[row][col];
            else if(col == 0) sum[row][col] = sum[row-1][col] + grid[row][col];
            else sum[row][col] = max(sum[row-1][col], sum[row][col-1]) + grid[row][col];
        }
    }
    return sum[H - 1][W - 1];
}

int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);                 

    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << maxSum(grid) << '\n';
}