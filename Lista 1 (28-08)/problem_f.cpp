#include <iostream>

using namespace std;

int main() {
    long h;
    unsigned long n;
    unsigned long long t = 0;

    cin >> n;

    while (n--) {
        cin >> h;
        t += 3 * (long) (h / 5);
        h = h % 5;
        while (h > 0) {
            t++;
            h -= (t % 3 == 0 ? 3 : 1);
        }
    }

    cout << t << "\n";

    return 0;
}