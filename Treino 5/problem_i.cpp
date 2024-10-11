#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, k;
    bool flag;
    vector<long long> numbers, prefix;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        numbers.resize(n, 0), prefix.resize(n + 1, 0);
        flag = true;

        for (int i = n - k + 1; i <= n; i++)
            cin >> prefix[i];
        
        if (k == 1) {
            cout << "Yes\n";
            numbers.clear(), prefix.clear();
            continue;
        }
        
        for (int i = n - k + 1; i < n; i++)
            numbers[i] = prefix[i + 1] - prefix[i];

        for (int i = n - k + 1; i < n - 1; i++) {
            if (numbers[i + 1] < numbers[i])
                flag = false;
        }

        if (flag == false || (numbers[n - k + 1] * (n - k + 1) < prefix[n - k + 1]))
            cout << "No\n";
        else
            cout << "Yes\n";

        numbers.clear(), prefix.clear();
    }

    return 0;
}