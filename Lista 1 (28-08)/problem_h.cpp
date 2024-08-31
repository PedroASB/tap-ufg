#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned long n, q, str_len;
    char c, d;
    string str;

    cin >> n >> str >> q;

    str_len = str.length();

    while (q--) {
        cin >> c >> d;
        for (int i = 0; i < str_len; i++) {
            if (str[i] == c) str[i] = d;
        }
    }

    cout << str;

    return 0;
}