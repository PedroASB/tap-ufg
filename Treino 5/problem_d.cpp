#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const ull MAX = 1e7+100;
vector<ull> prime_list;

void sieve(ull bound) {
    bitset<MAX> prime;

    prime.set();
    prime[0] = prime[1] = 0;

    for (ull i = 4; i <= bound; i += 2)
        prime[i] = 0;
    
    for (ull i = 3; (i * i) <= bound; i += 2) {
        if (prime[i]) {
            for (ull j = i * i; j < bound; j += i)
                prime[j] = 0;
        }
    }
    
    for (ull i = 2; i <= bound; i++) 
        if (prime[i]) prime_list.push_back(i);
}


int main() {
    int n;
    cin >> n;

    sieve(MAX - 1);

    cout << prime_list[n - 1] << '\n';

    return 0;
}