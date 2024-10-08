#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*1e5;

int parent[MAX], ranking[MAX], set_size[MAX];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranking[i] = 0;
        set_size[i] = 1;
    }
}

int find(int a) {
    if (a != parent[a]) parent[a] = find(parent[a]);
    return parent[a];
}

void unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;

    if (ranking[a] < ranking[b]) {
        parent[a] = b;
        set_size[b] += set_size[a];
    }
    else if (ranking[a] > ranking[b]) {
        parent[b] = a;
        set_size[a] += set_size[b];
    }
    else {
        parent[a] = b;
        set_size[b] += set_size[a];
        ranking[b]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, m, a, b;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        init(n);
        while (m--) {
            cin >> a >> b;
            unite(a, b);
        }
        cout << *max_element(set_size, set_size + n) << '\n';
    }
    
    return 0;
}