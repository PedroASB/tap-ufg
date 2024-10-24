#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "-1\n";
        return 0;
    }

    switch (a) {
        case 1:
            cout << (b == 2 ? 3 : 2) << '\n'; break;
        case 2:
            cout << (b == 1 ? 3 : 1) << '\n'; break;
        case 3:
            cout << (b == 1 ? 2 : 1) << '\n'; break;
    }

    return 0;
}