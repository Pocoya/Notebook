#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int> >& grid, int H, int W) {
    auto inside = [&](int row, int col) {
        return 0 <= row && row < H && 0 <= col && col < W;
    };
    
    vector<pair<int, int> > directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int> > distance(H, vector<int>(W, -1));
    queue<pair<int, int> > q;
    q.push({0, 0});
    distance[0][0] = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        for(pair<int, int> dir: directions) {
            int new_row = row + grid[row][col] * dir.first;
            int new_col = col + grid[row][col] * dir.second;
            if(inside(new_row, new_col) && distance[new_row][new_col] == -1){
                q.push({new_row, new_col});
                distance[new_row][new_col] = distance[row][col] + 1;
            }
        }
    }
    return distance[H - 1][W - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int H, W;
    cin >> H >> W;
    vector<vector<int> > grid(H, vector<int>(W));

    for(int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < W; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }

    cout << bfs(grid, H, W) << '\n';
}
