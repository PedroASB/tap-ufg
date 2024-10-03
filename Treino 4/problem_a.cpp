#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    long long pow = 1;
    cin >> a >> b;

    while (b--) pow *= a;

    cout << pow << '\n';

    return 0;
}