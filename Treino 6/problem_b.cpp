#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int q;
    unsigned int n;

    cin >> q;
    while (q--) {
        cin >> n;
        bitset<32> bits(n);
        cout << bits.flip().to_ulong() << '\n';
    }

    return 0;
}