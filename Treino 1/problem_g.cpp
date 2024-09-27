#include <bits/stdc++.h>

using namespace std;

#define MARK 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, r, x;
    map<int, int> defeated_by, participants;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        participants[i] = MARK; // Marca os participantes remanescentes
    }

    while (m--) {
        cin >> l >> r >> x;
        auto it_start = participants.lower_bound(l);
        auto it_end = participants.upper_bound(r);

        for (auto it = it_start; it != it_end;) {
            defeated_by[it->first] = x;
            it = participants.erase(it);
        }

        participants[x] = MARK;
        defeated_by[x] = 0;
    }

    for (int i = 1; i <= n; i++)
        cout << defeated_by[i] << " ";
    cout << '\n';

    return 0;
}