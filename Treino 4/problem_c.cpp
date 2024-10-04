#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long k;
    vector<long long> array, prefix_sum, sorted_array;

    cin >> n;
    array.resize(n), sorted_array.resize(n), prefix_sum.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        sorted_array[i] = array[i];
    }

    sort(sorted_array.begin(), sorted_array.end());
    
    for (int i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + sorted_array[i - 1];
    
    for (int i = 0; i < n; i++) {
        k = upper_bound(sorted_array.begin() + 1, sorted_array.end(), array[i]) - sorted_array.begin() + 1;
        cout << prefix_sum[n] - prefix_sum[k - 1] << '\n';
    }

    return 0;
}