#include <bits/stdc++.h>
using namespace std;

int R, C;
int min_d = INT_MAX;
int a[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> mine;
vector<vector<bool>> visited;

void flood(int x, int y, int cnt, int mve) {
    vector<vector<bool>> visit(x, vector<bool>(y));

    if (x < 0 || y < 0 || x >= R || y >= C || mine[x][y] == 0 || visit[x][y]) {
        return;
    }
    visit[x][y] = true;
    if (y == C-1) {
        min_d = min(min_d, cnt);
        return;
    }
    if (mine[x][y] == 1) {
        for (int i = 0; i < 4; i++) {
            int nx = x + a[i][0];
            int ny = y + a[i][1];
            flood(nx, ny, cnt + 1, mve + 1);
        }
    }
    visit[x][y] = false; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    mine.resize(R, vector<int>(C));
    visited.resize(R, vector<bool>(C));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> mine[i][j];
            visited[i][j] = false;
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

    for (int i=0; i<R; i++) {
        flood(i, 0, 1, 0);
    } 

    if (min_d == INT_MAX) {
        cout << "No route" << endl;
    }
    else {
        cout << min_d << endl;
    } 
    /*for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << mine[i][j] << ' ';
        }
        cout << endl;
    } */

    return 0;
}
