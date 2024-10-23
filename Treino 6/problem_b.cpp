#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    unsigned int n, q;

    cin >> q;

    while (q--) {
        cin >> n;
        for (int i = 0; i < 32; i++)
            n ^= (1 << i);
        cout << n << '\n';
    }

    return 0;
}