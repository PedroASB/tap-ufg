#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, k, x, type;
    vector<int> a;

    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> q;
    while (q--) {
        cin >> type;
        cin >> k;
        if (type == 1)
            cin >> x;
        switch (type) {
            case 1: a[k - 1] = x; break;
            case 2: cout << a[k - 1] << '\n'; break;
        }
    }

    return 0;
}