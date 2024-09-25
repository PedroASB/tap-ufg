#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, q, a, b;
    vector<long long> numbers, prefix;

    cin >> n >> q;
    numbers.resize(n), prefix.resize(n + 1);

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        prefix[i + 1] = prefix[i] + numbers[i];
    }
    
    while (q--) {
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}