#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    int f = 1;
    while (n > 0) {
        f *= n;
        n--;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << factorial(n) << '\n';

    return 0;
}