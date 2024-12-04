#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    string str;

    cin >> l >> r >> str;

    for (int i = 0; i < l - 1; i++)
        cout << str[i];
    
    for (int i = r - 1; i >= l - 1; i--)
        cout << str[i];

    for (int i = r, n = str.size(); i < n; i++)
        cout << str[i];

    return 0;
}