#include <bits/stdc++.h>

using namespace std;

int number_of_divisors(int n) {
    int n2, b = 1e3;
    set<int> divisors;

    for (int d = 1; d <= b; d++)
        if (n % d == 0) {
            divisors.insert(d);
            divisors.insert(n / d);
        }

    n2 = n / b;
    for (int d = b + 1; d <= n2; d++)
        if (n % d == 0) divisors.insert(d);

    return divisors.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    while (n--) {
        cin >> x;
        cout << number_of_divisors(x) << '\n';
    }

    return 0;
}