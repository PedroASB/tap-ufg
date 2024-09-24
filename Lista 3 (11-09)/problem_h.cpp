#include <bits/stdc++.h>

using namespace std;

#define NEVER -1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, curr_song, max_seq = 0, p1, p2;
    vector<int> songs;
    map<int, int> last_seen;

    cin >> n;
    songs.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> songs[i];
        last_seen[songs[i]] = NEVER;
    }

    for (p2 = 0, p1 = 0; p2 < n; p2++) {
        curr_song = songs[p2];

        if (last_seen[curr_song] != NEVER) {
            for (int i = p1; i <= last_seen[curr_song]; i++) {
                last_seen[songs[i]] = NEVER;
                p1++;
            }
        }

        last_seen[curr_song] = p2;
        max_seq = max(p2 - p1 + 1, max_seq);
    }

    cout << max_seq << '\n';

    return 0;
}