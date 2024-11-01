#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5+100;

int parent[MAX], ranking[MAX], set_size[MAX];

void init(int n) {
    for (int i = 1; i <= n; i++) {
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

    int n, m, a, b;
    set<int> parents;

    cin >> n >> m;
    init(n);

    while (m--) {
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 1; i <= n; i++)
        parents.insert(find(i));

    int k = parents.size() - 1;
    cout << k << '\n';

    if (k < 1) return 0; 

    set<int>::iterator it = parents.begin();

    cout << *it << ' ';
    while (++it != --parents.end())
        cout << *it << '\n' << *it << ' ';
    cout << *it;
    
    return 0;
}