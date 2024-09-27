#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, h, posters, prev_h = -1, last_diff_h = -1, scnd_last_diff_h = -1;
    cin >> n;

    posters = 0;
    while (n--) {
        cin >> l >> h;
        
        if (h != prev_h) {
            scnd_last_diff_h = last_diff_h;
            last_diff_h = prev_h;
        }

        if (h > prev_h || (h < prev_h && h != scnd_last_diff_h))
            posters++;

        prev_h = h;
    }

    cout << posters << '\n';

    return 0;
}