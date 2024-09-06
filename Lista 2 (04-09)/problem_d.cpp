#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, ferry, n_lines, car, capacity, n_crossings;
    string car_bank, side;

    map<string, queue<int>> bank;

    cin >> n_tests;
    while (n_tests--) {
        cin >> ferry >> n_lines;
        capacity = ferry * 100;

        while (n_lines--) {
            cin >> car >> car_bank;
            bank[car_bank].push(car);
        }

        n_crossings = 0;
        side = "left";
        while (true) {
            while (true) {
                if (!bank[side].empty() && capacity >= bank[side].front()) {
                    capacity -= bank[side].front();
                    bank[side].pop();
                } else {
                    n_crossings++;
                    capacity = ferry * 100;
                    break;
                }
            }
            if (bank["left"].empty() && bank["right"].empty())
                break;
            side == "left" ? side = "right" : side = "left";
        }

        cout << n_crossings << '\n';
    }
    
    return 0;
}