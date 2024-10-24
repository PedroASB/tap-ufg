#include <bits/stdc++.h>

using namespace std;

vector<int> distinct_divisors(int n) {
    vector<int> divisors;
    for (int d = 2; d <= n; d++)
        if (n % d == 0) divisors.push_back(d);
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans, max_gcdness = -1;
    vector<int> array, divisors;
    map<int, int> gcdness;

    cin >> n;
    array.resize(n);

    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    for (int i = 0; i < n; i++) {
        divisors = distinct_divisors(array[i]);
        for (auto d: divisors)
            gcdness[d]++;
    }

    for (auto g: gcdness) {
        if (g.second > max_gcdness) {
            max_gcdness = g.second;
            ans = g.first;
        }
    }
    cout << ans << '\n';

    return 0;
}