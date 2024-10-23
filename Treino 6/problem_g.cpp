#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull power(ull a, ull b) {
    ull pow = 1;
    while (b--) pow *= a;
    return pow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ull n;
    cin >> n;

    if (n == 0)
        cout << "1\n";
    else
        cout << power(2, 64 - __builtin_clzll(n) - __builtin_popcountll(n)) << '\n';
    
    return 0;
}
