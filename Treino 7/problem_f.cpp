#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b;
    ull gcd_value;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        gcd_value = gcd(a, b);
        cout << (a * (b / gcd_value)) << ' ' << gcd_value << '\n';
    }
    
    return 0;
}