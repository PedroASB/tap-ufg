#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, w, i, j, alice, bob, num_candies;
    vector<int> candies;
    priority_queue<int> max_candies;

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> w;
            candies.push_back(w);
        }

        i = 0; j = n - 1;
        alice = candies[0]; bob = candies[n - 1];
        num_candies = 2;
    
        while (i < j) {
            if (alice == bob) {
                max_candies.push(num_candies);
                i++;
                alice += candies[i];
                num_candies++;
            } 
            else if (alice > bob) {
                j--;
                bob += candies[j];
                num_candies++;
            }
            else {
                i++;
                alice += candies[i];
                num_candies++;
            }
        }
        
        if (!max_candies.empty()) {
            cout << max_candies.top() << '\n';
            while (!max_candies.empty()) max_candies.pop();
        } else cout << "0\n";
        candies.clear();
    }

    return 0;
}