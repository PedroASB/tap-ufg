#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    unsigned int n, t, aux;

    cin >> t;

    while (t--) {
        cin >> n;
        bitset<32> bits(n);
        for (int i = 0; i < 31; i += 2) {
            aux = bits[i];
            bits[i] = bits[i + 1];
            bits[i + 1] = aux;
        }
        cout << bits.to_ulong() << '\n';
    }
    
    return 0;
}