#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c, odd = '_';
    map<char, int> num_chars;
    queue<char> char_queue;
    stack<char> char_stack;

    while (cin.peek() != '\n' && cin >> c)
        num_chars[c]++;

    for (auto e : num_chars) {
        if ((e.second & 1) == 0) 
            for (int i = 0, k = (e.second >> 1); i < k; i++) {
                char_queue.push(e.first); char_stack.push(e.first);
            }
        else if (odd == '_') 
            odd = e.first;
        else {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }

    while (!char_queue.empty()) {
        cout << char_queue.front(); char_queue.pop();
    }

    while (num_chars[odd]--)
        cout << odd;

    while (!char_stack.empty()) {
        cout << char_stack.top(); char_stack.pop();
    }
    
    return 0;
}