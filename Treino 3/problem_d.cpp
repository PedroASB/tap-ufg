#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, type, l, r;
    vector<long long> costs, prefix, s_prefix;

    cin >> n;
    costs.resize(n), prefix.resize(n + 1), s_prefix.resize(n + 1);
    prefix[0] = s_prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
        prefix[i + 1] = prefix[i] + costs[i];
    }

    sort(costs.begin(), costs.end());

    for (int i = 0; i < n; i++) {
        s_prefix[i + 1] = s_prefix[i] + costs[i];
    }

    cin >> m;
    while (m--) {
        cin >> type >> l >> r;
        switch (type) {
            case 1:
                cout << prefix[r] - prefix[l - 1] << '\n'; break;
            case 2:
                cout << s_prefix[r] - s_prefix[l - 1] << '\n'; break;
        }
    }

    return 0;
}