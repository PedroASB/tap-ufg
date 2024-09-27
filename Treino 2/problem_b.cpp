#include <bits/stdc++.h>

using namespace std;

bool made_all_products(vector<int> machines, long long instant, int num_products) {
    long long products_made = 0;
    for (auto time_per_product : machines) {
        products_made += (int) (instant / time_per_product);
    }
    return products_made >= num_products;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r, c, t, ans = 0, num_products, num_machines, fastest_machine = 1e9;
    vector<int> machines; // Tempo gasto por cada máquina para fazer 1 produto

    cin >> num_machines >> num_products;

    while (num_machines--) {
        cin >> t;
        machines.push_back(t);
        if (t < fastest_machine) fastest_machine = t;
    }

    l = 0, r = fastest_machine * num_products;
    while (l <= r) {
        c = l + ((r - l) >> 1);
        
        if (made_all_products(machines, c, num_products)) {
            ans = c;
            r = c - 1;
        }
        else
            l = c + 1;
    }

    cout << ans << '\n';

    return 0;
}