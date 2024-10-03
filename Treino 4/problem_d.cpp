#include <bits/stdc++.h>

using namespace std;
const int MAX = 2*1e5;

int parent[MAX], ranking[MAX];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranking[i] = 0;
    }
}

int find(int a) {
    if (a != parent[a]) parent[a] = find(parent[a]);
    return parent[a];
}

void unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;

    if (ranking[a] < ranking[b]) 
        parent[a] = b;
    else if (ranking[a] > ranking[b]) 
        parent[b] = a;
    else {
        parent[a] = b;
        ranking[b]++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, t, u, v;
    cin >> n >> q;
    init(n);

    while (q--) {
        cin >> t >> u >> v;
        switch (t) {
            case 0:
                unite(u, v);
                break;
            case 1:
                cout << (find(u) == find(v)) << '\n';
                break;
        }
    }
        
    return 0;
}