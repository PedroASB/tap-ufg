#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    min_heap heap;
    int n, box, required_box = 1, n_reorders = 0;   
    stack<int> box_stack;

    cin >> n;
    n = 2 * n;

    // while (n--) {
    //     cin >> str;
    //     if (str == "add") {
    //         cin >> box;
    //         box_stack.push(box);
    //     } else {
    //         if (box_stack.top() == required_box);
    //         required_box++;
    //     }
    // }
    
    cout << n_reorders << '\n';
    
    return 0;
}