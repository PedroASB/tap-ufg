#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<char> str;
    char c;

    while (cin.peek() != '\n' && cin >> c) {
        c == str.back() ? str.pop_back() : str.push_back(c);
    }

    for (auto ch : str) {
        cout << ch;
    }
    
    cout << "\n";
    
    return 0;
}