#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    map<string, int> already_present;
    string str;
    cin >> n;

    while (n--) {
        cin >> str;
        already_present[str] ? cout << "YES\n" : cout << "NO\n";
        already_present[str] = 1;
    }

    return 0;
}