#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    unsigned int n, i;

    cin >> n >> i;

    cout << (n & (1 << i) ? "true\n" : "false\n");

    return 0;
}