#include <bits/stdc++.h>

using namespace std;

const int MAX = (2 * 1e5);

int parent[MAX], ranking[MAX], set_size[MAX], num_components, max_set = 0;

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranking[i] = 0;
        set_size[i] = 1;
    }
    num_components = n;
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
        max_set = max(set_size[b], max_set);
    }
    else if (ranking[a] > ranking[b]) {
        parent[b] = a;
        set_size[a] += set_size[b];
        max_set = max(set_size[a], max_set);
    }
    else {
        parent[a] = b;
        set_size[b] += set_size[a];
        ranking[b]++;
        max_set = max(set_size[b], max_set);
    }

    num_components--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    string person_a, person_b;

    cin >> n >> m;
    init(n);

    while (m--) {
        cin >> a >> b;
        unite(a, b);   
        cout << num_components << ' ';
        cout << max_set << '\n';
    }
    
    return 0;
}