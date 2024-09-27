#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    unsigned long n, q;
    char c, d;
    string str;

    cin >> n >> str >> q;

    while (q--) {
        cin >> c >> d;
        if (c == d)
            continue;
        replace(str.begin(), str.end(), c, d);
    }

    cout << str << "\n";

    return 0;
}