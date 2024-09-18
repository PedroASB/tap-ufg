#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, lower_bound, upper_bound, x;
    string sign;
    char answer;

    upper_bound = 2e9;
    lower_bound = -2e9;

    cin >> n;

    while (n--) {
        cin >> sign >> x >> answer;

        if (answer == 'N') {
            if (sign == ">") sign = "<=";
            else if (sign == ">=") sign = "<";
            else if (sign == "<") sign = ">=";
            else /* sign == "<=" */ sign = ">";
        }

        if (sign == ">")
            lower_bound = (x + 1 > lower_bound) ? x + 1 : lower_bound;

        else if (sign == ">=")
            lower_bound = (x > lower_bound) ? x : lower_bound;

        else if (sign == "<")
            upper_bound = (x - 1 < upper_bound) ? x - 1 : upper_bound;
                
        else // sign == "<="
            upper_bound = (x < upper_bound) ? x : upper_bound;
    }

    if (lower_bound <= upper_bound)
        cout << lower_bound << '\n';
    else
        cout << "Impossible\n";

    return 0;
}