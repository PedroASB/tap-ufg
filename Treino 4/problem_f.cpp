#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
const int MAX = (2 * 1e5);

map<string, string> parent;
map<string, int> ranking;
map<string, int> set_size;

string find(string a) {
    if (a != parent[a]) parent[a] = find(parent[a]);
    return parent[a];
}

void unite(string a, string b) {
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
    
    int t, n;
    string person_a, person_b;
    vector<pair<string, string>> queries;
    cin >> t;

    while (t--) {
        cin >> n;
        queries.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> person_a >> person_b;
            queries[i].F = person_a, queries[i].S = person_b;
            parent[person_a] = person_a;
            parent[person_b] = person_b;
            ranking[person_a] = ranking[person_b] = 0;
            set_size[person_a] = set_size[person_b] = 1;
        }

        for (int i = 0; i < n; i++) {
            unite(queries[i].F, queries[i].S);
            cout << set_size[find(queries[i].F)] << '\n';
        }

        queries.clear();
    }
    
    return 0;
}