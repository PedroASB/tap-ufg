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

ull distinct_divisors(ull number) {
    ull prime = prime_list[0], index = 0, counter = 0;

    if (number == 1) return 1;

    while (prime * prime <= number) {
        if (number % prime == 0) {
            counter++;
            while (number % prime == 0) number /= prime;
        }
        prime = prime_list[++index];
    }
    
    if (number != 1) counter++;
           
    return counter;
}

int main() {
    int n, almost_primes = 0;
    sieve(MAX - 1);

    cin >> n;

    for (int i = 1; i <= n; i++) 
        if (distinct_divisors(i) == 2) almost_primes++;

    cout << almost_primes << '\n';

    return 0;
}