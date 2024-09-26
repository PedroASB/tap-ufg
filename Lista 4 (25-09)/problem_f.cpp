#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, a, b, x;
    vector<int> numbers, prefix;

    cin >> n >> q;
    numbers.resize(n), prefix.resize(n + 1);

    cin >> x;
    prefix[0] = 0, prefix[1] = numbers[0] = x;

    for (int i = 1; i < n; i++) {
        cin >> numbers[i];
        prefix[i + 1] = prefix[i] ^ numbers[i];
    }

    while (q--) {
        cin >> a >> b;
        cout << (prefix[b] ^ prefix[a - 1]) << '\n';
    }

    return 0;
}