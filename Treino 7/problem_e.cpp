#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, k = 0;
    cin >> a >> b >> c;

    for (int i = a; i <= b; i++)
        if (c % i == 0) k++;
    
    cout << k << '\n';
    
    return 0;
}