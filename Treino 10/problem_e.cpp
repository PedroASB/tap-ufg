#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, patt, str;
    cin >> text >> patt;
    str = patt + '*' + text;
    
    int n = str.size();
    int z[n] = {0};
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            z[i]++;

        if (i + z[i] > r)
            r = (l = i) + z[i];
    }

    int count = 0;
    for (int i = 0; i <= (int) text.size() - 1; i++) {
        if (z[i + patt.size() + 1] == (int) patt.size())
            count++;
    }

    cout << count << '\n';

    return 0;
}