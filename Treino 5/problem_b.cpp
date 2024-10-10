#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans = 0;
    string str;
    map<string, int> counter;

    cin >> n >> m;

    while (n--) {
        cin >> str;
        counter[str.substr(3, 5)]++;
    }

    while (m--) {
        cin >> str;
        if (counter[str] != -1) {
            ans += counter[str];
            counter[str] = -1;
        }
    }

    cout << ans << '\n';

    return 0;
}