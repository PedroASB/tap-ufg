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

vector<ull> prime_factorization(ull number) {
    vector<ull> prime_factors;
    ull index = 0, prime = prime_list[0];

    while (prime * prime <= number) {
        if (number % prime == 0) {
            prime_factors.push_back(prime);
            while (number % prime == 0) number /= prime;
        }
        prime = prime_list[++index];
    }
    
    if (number != 1)
        prime_factors.push_back(number);
    
    return prime_factors;
}


int main() {
    ull n;
    vector<ull> prime_factors;
    sieve(MAX - 1);

    cin >> n;

    prime_factors = prime_factorization(n);

    for (auto pf : prime_factors)
        cout << pf << '\n';

    return 0;
}