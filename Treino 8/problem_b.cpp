#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, ans, max = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        if (h > max) {
            max = h;
            ans = i;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
