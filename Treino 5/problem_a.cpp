#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long a, b;

    cin >> a >> b;

    cout << (a % b == 0 ? a / b : a / b + 1) << '\n';

    return 0;
}