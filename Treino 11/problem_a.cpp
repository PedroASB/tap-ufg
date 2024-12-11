#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n, m, value, salary;
    string word;
    map<string, int> hay;
    cin >> m >> n;

    while (m--) {
        cin >> word >> value;
        hay[word] = value;
    }
    
    while (n--) {
        salary = 0;
        do {
            cin >> word;
            salary += hay[word];
        } while (word != ".");
        cout << salary << '\n';
    }

    return 0;
}