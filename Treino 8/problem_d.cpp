#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    map<int, int> love;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> f;
        love[i] = f;
    }

    for (int i = 1; i <= n; i++) {
        if (love[love[love[i]]] == i) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}