#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, x;
    cin >> n >> m;
    vector<int> sorted;

    while (n--) {
        cin >> x;
        sorted.push_back(x);
    }

    sort(sorted.begin(), sorted.end());

    while (m--) {
        cin >> x;
        cout << upper_bound(sorted.begin(), sorted.end(), x) - sorted.begin() << " ";
    }
    cout << '\n';

    return 0;
}