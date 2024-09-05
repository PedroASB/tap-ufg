#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, l, r, time;

    cin >> t;
    while (t--) {
        time = 1;
        cin >> n;
        while (n--) {
            cin >> l >> r;
            if (time <= r) {
                if (l > time) time = l;
                cout << time << '\n';
                time++;
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}