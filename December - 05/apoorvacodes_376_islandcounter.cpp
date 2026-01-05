#include <iostream>
#include <vector>
using namespace std;

int R, C;

int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

void dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] == 0) return;

    grid[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        dfs(grid, r + dRow[i], c + dCol[i]);
    }
}

int countIslands(vector<vector<int>>& grid) {
    int islands = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 1) {
                islands++;
                dfs(grid, r, c); 
            }
        }
    }
    return islands;
}

int main() {
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));

    // Input grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countIslands(grid) << endl;
    return 0;
}
