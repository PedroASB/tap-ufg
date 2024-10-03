#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    int row = 8;
    char col;

    for (int i = 0; i < 8; i++) {
        cin >> str;
        col = 'a';
        for (int j = 0; j < 8; j++) {
            if (str[j] == '*') cout << col << row << '\n';
            col++;
        }
        row--;
    }
        
    return 0;
}