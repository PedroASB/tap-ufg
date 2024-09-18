#include <bits/stdc++.h>

using namespace std;


bool my_function(vector<int> machines, int instant, int num_products) {
    int products_made = 0;
    for (auto time_per_product : machines) {
        products_made += (int) (instant / time_per_product);
    }
    return products_made >= num_products;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r, c, t, num_products, num_machines;
    vector<int> machines; // Tempo gasto por cada máquina

    int limit = 14;

    cin >> num_machines >> num_products;

    while (num_machines--) {
        cin >> t;
        machines.push_back(t);
    }
    
    // if (my_function(machines, 5, 20) == true) {
    //     cout << "Hey\n";
    // } else cout << "Nope\n";
    // return 0;

    l = 0;
    // r = time[n - 1] - time[0];
    r = limit;

    while (l <= r) {
        c = l + ((r - l) >> 1);
        
        if (!my_function(machines, c, num_products))
            l = c + 1;
        else
            r = c - 1;
    }

    cout << r << '\n';

    return 0;
}