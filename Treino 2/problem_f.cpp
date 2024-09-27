#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num, target, sum = 0, n_subarrays = 0;
    queue<int> q;

    cin >> n >> target;
    
    while(n--) {
        cin >> num;
        sum += num;
        q.push(num);

        while (sum > target) {
            sum -= q.front();
            q.pop();
        }

        if (sum == target) {
            sum -= q.front();
            q.pop();
            n_subarrays++;
        }
    }

    cout << n_subarrays << '\n';

    return 0;
}