#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, j = 1;
    long long sum, min_sum;
    vector<long long> h, pre;

    cin >> n >> k;
    h.resize(n), pre.resize(n + 1);

    pre[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        pre[i + 1] = pre[i] + h[i];
    }
 
    min_sum = pre[n];
    for (int l = 1, r = k; r <= n; l++, r++) {
        sum = pre[r] - pre[l - 1];
        if (sum < min_sum) {
            min_sum = sum;
            j = l;
        }
    } 

    cout << j << '\n';

    return 0;
}