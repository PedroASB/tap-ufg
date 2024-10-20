#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    unsigned int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        bitset<32> bits(n);
        string str = bits.to_string();
        reverse(str.begin(), str.end());
        bitset<32> reversed_bits(str);
        cout << reversed_bits.to_ulong() << '\n';
    }
    
    return 0;
}
