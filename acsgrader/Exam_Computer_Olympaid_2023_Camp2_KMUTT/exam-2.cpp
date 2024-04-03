#include <bits/stdc++.h>
using namespace std;

int R, C;
int min_d = INT_MAX;
int a[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> mine;
vector<vector<bool>> visited;

void flood(int x, int y, int cnt) {
    // Check bounds and whether the cell is safe and unvisited
    if (x < 0 || y < 0 || x >= R || y >= C || mine[x][y] == 0 || visited[x][y]) {
        return;
    }
    // Mark the current cell as visited
    visited[x][y] = true;
    // Check if we've reached the last column
    if (y == C-1) {
        min_d = min(min_d, cnt);
        // Backtrack: mark the current cell as unvisited before returning
        visited[x][y] = false;
        return;
    }
    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int nx = x + a[i][0];
        int ny = y + a[i][1];
        flood(nx, ny, cnt + 1);
    }
    // Backtrack: Reset visit status on backtrack
    visited[x][y] = false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    mine.resize(R, vector<int>(C));
    visited.resize(R, vector<bool>(C, false)); // Initialize visited as false for all cells
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mine[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mine[i][j] == 0) {
                if (i > 0 && j < C-1) mine[i-1][j+1] = 0;
                if (j < C-1) mine[i][j+1] = 0;
                if (i < R-1 && j < C-1) mine[i+1][j+1] = 0;
                if (i > 0) mine[i-1][j] = 0;
                if (i < R-1) mine[i+1][j] = 0;
                if (i > 0 && j > 0) mine[i-1][j-1] = 0;
                if (j > 0) mine[i][j-1] = 0;
                if (i < R-1 && j > 0) mine[i+1][j-1] = 0;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        if (mine[i][0] != '0') {
            flood(i, 0, 1);
        }
    }

    if (min_d == INT_MAX) {
        cout << "No route" << endl;
    } else {
        cout << min_d << endl;
    }

    return 0;
}
