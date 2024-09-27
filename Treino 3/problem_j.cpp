#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;
    int n, q, n_trees;
    vector<vector<long long>> prefix;
    pair<int, int> corner_1, corner_2;

    cin >> n >> q;
    prefix.resize(n);

    for (int i = 0; i < n; i++) {
        prefix[i].resize(n + 1, 0); 

        for (int j = 0; j < n; j++) {
            cin >> c;
            prefix[i][j + 1] = prefix[i][j] + (c == '*' ? 1 : 0);
        }
    }

    while (q--) {
        cin >> corner_1.Y >> corner_1.X >> corner_2.Y >> corner_2.X;
        corner_1.Y--, corner_2.Y--;

        n_trees = 0;
        for (int i = corner_1.Y; i <= corner_2.Y; i++)
            n_trees += prefix[i][corner_2.X] - prefix[i][corner_1.X - 1];

        cout << n_trees << '\n';
    }

    return 0;
}