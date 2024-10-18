#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ull i, n;

    cin >> n >> i;
    bitset<64> bits(n);

    cout << (bits.test(i) ? "true\n" : "false\n");

    return 0;
}