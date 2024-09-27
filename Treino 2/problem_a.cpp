#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, target, sum;
    vector<pair<int, int>> numbers;

    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push_back(make_pair(a, i));
    }
   
    sort(numbers.begin(), numbers.end());
    
    int i = 0; int j = n - 1;
    while (i < j) {
        sum = numbers[i].F + numbers[j].F; 
        if (sum == target) {
            if (numbers[i].S + 1 > numbers[j].S + 1)
                cout << numbers[j].S + 1 << " " << numbers[i].S + 1 << '\n';
            else
                cout << numbers[i].S + 1 << " " << numbers[j].S + 1 << '\n';
            return 0;
        } else if (sum > target)
            j--;
        else
            i++;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}