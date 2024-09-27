#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> station;
    queue<int> train;
    int n, coach;

    while (cin >> n, n) {
        while (cin >> coach, coach) {
            train.push(coach);

            for (int i = 1; i < n; i++) {
                cin >> coach;
                train.push(coach);
            }

            for (int i = 1; i <= n;) {
                if (train.front() == i) {
                    train.pop();
                    i++;
                } 
                else if (train.front() < i && !station. empty() && station.top() == train.front()) {
                    station.pop();
                    train.pop();
                } 
                else {
                    station.push(i);
                    i++;
                }
            }

            while (!station.empty()) {
                if (train.front() == station.top()) {
                    station.pop();
                    train.pop();
                } else {
                    break;
                }
            }
            
            train.empty() ? cout << "Yes\n" : cout << "No\n";

            while (!train.empty()) train.pop();
            while (!station.empty()) station.pop();
        }
        cout << "\n";
    }

    
    return 0;
}