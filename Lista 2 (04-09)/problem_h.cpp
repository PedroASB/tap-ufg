#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, number, total_cost;
    int aux_1, aux_2; 
    min_heap heap;

    while (cin >> n, n) {
        total_cost = 0;

        while (n--) {
            cin >> number;
            heap.push(number);
        }

        while (true) {
            aux_1 = heap.top();
            heap.pop();
            if (!heap.empty()) {
                aux_2 = heap.top();
                heap.pop();
                heap.push(aux_1 + aux_2);
                total_cost += aux_1 + aux_2;
            } else break;
        }

        cout << total_cost << '\n';
    }

    return 0;
}