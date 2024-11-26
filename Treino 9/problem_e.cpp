#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> point;

vector<vector<int>> grid;
map<point, bool> visited;
int h, w;

// void print_point(point p) {
//     cout << "(" << p.first << "," << p.second << ") ";
// }

bool check(int x, int y) {
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int bfs(point source) {
    int i, j, x, y, k, level, moves = 0;
    point current, adjacent;
    array<array<int, 8>, 2> step;

    queue<point> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        level = q.size();

        while (level--) {
            current = q.front(); q.pop();
            i = current.first, j = current.second;

            if (i == h - 1 && j == w - 1)
                return moves;

            // cout << "Current: " << grid[i][j] << " ";
            // print_point(make_pair(i, j));

            k = grid[i][j];
            if (k == 0) continue;

            step = {{{-k, k, 0, 0}, {0, 0, k, -k}}};         

            // cout << "\nAdjacents of " << grid[i][j] << ":\n";
            for (int dir = 0; dir < 4; dir++) {
                x = i + step[0][dir], y = j + step[1][dir];
                adjacent = make_pair(x, y);
                if (check(x, y) && !visited[adjacent]) {
                    q.push(adjacent);
                    visited[adjacent] = true;
                    // print_point(adjacent);
                    // cout << grid[x][y] << " | ";
                }
            }
            // cout << "\n\n";
        }

        moves++;
    }

    return -1;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char digit;
    int moves;
    cin >> h >> w;

    grid.resize(h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> digit;
            grid[i].push_back((int)digit - 48);
        }
    }

    moves = bfs(make_pair(0, 0));

    cout << moves << '\n';

    return 0;
}