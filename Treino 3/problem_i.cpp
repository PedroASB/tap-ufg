#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, a, target, prefix_sum = 0, subarrays = 0;
    map<long long, long long> appeared_sum;

    cin >> n >> target;

    appeared_sum[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        prefix_sum += a;
        subarrays += appeared_sum[prefix_sum - target];
        appeared_sum[prefix_sum]++;
    }

    cout << subarrays << '\n';

    return 0;
}