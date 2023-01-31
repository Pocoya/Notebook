#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<char> >& grid, int H, int W, int tt) {
    auto inside = [&] (int row, int col) {
        return 0 <= row && row < H && 0 <= col && col < W;
    };

    vector<pair<int, int> > directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool> > visited(H, vector<bool>(W, false));
    int count = 0;
    for(int row = 0; row < H; ++row) {
        for(int col = 0; col < W; ++col) {
            if(!visited[row][col] && grid[row][col] == '-') {
                count++;
                queue<pair<int, int> > q;
                q.push({row, col});
                visited[row][col] = true;
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for(pair<int, int> dir: directions) {
                        int new_row = p.first + dir.first;
                        int new_col = p.second + dir.second;

                        if(inside(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '-') {
                            q.push({new_row, new_col});
                            visited[new_row][new_col] = true;
                        }
                    }
                }
            }
        }
    }
    cout << "Case " << tt << ": " << count <<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    int tt = 0;
    while(cin >> H >> W) {
        tt++;
        vector<vector<char> > grid(H, vector<char>(W));
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                cin >> grid[i][j];
            }
        }
        
        bfs(grid, H, W, tt);
    }
}
