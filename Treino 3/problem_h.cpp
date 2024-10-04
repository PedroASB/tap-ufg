#include <bits/stdc++.h>

using namespace std;

// Temporary code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, k;
    vector<long long> numbers, prefix;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        numbers.resize(n, 0), prefix.resize(n + 1, 0);

        for (int i = n - k + 1; i <= n; i++)
            cin >> prefix[i];
        
        for (int i = n - k + 1; i < n; i++)
            numbers[i] = prefix[i + 1] - prefix[i];

        // cin >> prefix[n - k + 1];
        // for (int i = n - k + 2; i <= n; i++) {
        //     cin >> prefix[i];
        //     numbers[i - 1] = prefix[i] - prefix[i - 1];
        // }
        
        // numbers
        cout << "n: ";
        for (int i = 0; i < n; i++)
            cout << setw(2) << numbers[i] << " ";
        cout << '\n';

        // prefix
        cout << "p: ";
        for (int i = 0; i <= n; i++)
            cout << setw(2) << prefix[i] << " ";
        cout << "\n----\n";
        

        for (int i = n - k; i > 0; i--) {
            prefix[i] = prefix[i + 1] - 1;
            numbers[i] = prefix[i + 1] - prefix[i];
        }
        numbers[0] = prefix[1];


        cout << "n: ";
        for (int i = 0; i < n; i++)
            cout << setw(2) << numbers[i] << " ";
        cout << '\n';
        cout << "p: ";
        for (int i = 0; i <= n; i++)
            cout << setw(2) << prefix[i] << " ";
        cout << '\n';


        cout << (numbers[0] <= numbers[1] ? "Yes\n" : "No\n");
        cout << '\n';

        numbers.clear(), prefix.clear();
    }

    return 0;
}