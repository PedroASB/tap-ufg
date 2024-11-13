#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;
const string SNUKE = "snuke";
const point INVALID_POINT = make_pair(-1, -1);

vector<vector<char>> grid;
int h, w;

bool check(int x, int y) {
    return (x >= 0 && x < h && y >= 0 && y < w);
}

point find_snuke(point source) {
    int x, y;
    bool found;
    int step[2][8] = {{0, -1, -1, -1, 0, 1, 1, 1}, 
                      {1, 1, 0, -1, -1, -1, 0, 1}};

    for (int dir = 0; dir < 8; dir++) {
        x = source.first + step[0][dir];
        y = source.second + step[1][dir];
        
        found = true;
        for (int pos = 1; pos < 5; pos++) {
            if (!check(x, y) || grid[x][y] != SNUKE[pos]) {
                found = false;
                break;
            }
            x += step[0][dir];
            y += step[1][dir];
        }

        if (found)
            return make_pair(x - step[0][dir], y - step[1][dir]);
    }

    return INVALID_POINT;
}

void print_path(point a, point b) {
    int x_a = a.first + 1, y_a = a.second + 1;
    int x_b = b.first + 1, y_b = b.second + 1;
    int step_x, step_y;

    if (x_a < x_b) step_x = 1;
    else if (x_a > x_b) step_x = -1;
    else step_x = 0;

    if (y_a < y_b) step_y = 1;
    else if (y_a > y_b) step_y = -1;
    else step_y = 0;

    for (int i = 0; i < 5; i++) {
        cout << x_a << ' ' << y_a << '\n';
        x_a += step_x;
        y_a += step_y;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    point source, result;
    cin >> h >> w;

    grid.resize(h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c;
            grid[i].push_back(c);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] != 's')
                continue;
            source = make_pair(i, j);
            result = find_snuke(source);
            if (result != INVALID_POINT) {
                print_path(source, result);
                return 0;
            }
        }
    }

    return 0;
}