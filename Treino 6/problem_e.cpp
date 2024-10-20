#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ui t, n, a;

    cin >> t;
    while (t--) {
        cin >> n;

        if (!(n >> __builtin_ffs(n))) {
            cout << "-1\n";
            continue;
        }

        a = (ui) pow(2, __builtin_ffs(n) - 1);
        cout << a << " " << n - a << '\n';
    }
    
    return 0;
}
