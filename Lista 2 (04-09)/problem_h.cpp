#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, number, cost, total_cost;
    min_heap heap;

    while (cin >> n) {
        if (n == 0) break;

        cost = total_cost = 0;

        while (n--) {
            cin >> number;
            heap.push(number);
        }

        cost = heap.top();
        heap.pop();

        while (!heap.empty()) {
            cost += heap.top();
            heap.pop();
            total_cost += cost;
        }

        cout << total_cost << '\n';
    }

    return 0;
}