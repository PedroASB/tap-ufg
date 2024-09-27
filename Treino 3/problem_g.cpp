#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, q, a, l, r, k, new_sum;
    vector<int> prefix;

    cin >> t;
    while (t--) {
        cin >> n >> q;
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> a;
            prefix[i + 1] = prefix[i] + a;
        }
        
        while (q--) {
            cin >> l >> r >> k;     
            new_sum = prefix[n] + (r - l + 1) * k - (prefix[r] - prefix[l - 1]);
            cout << (new_sum & 1 ? "Yes\n" : "No\n");
        }
        
    }

    return 0;
}