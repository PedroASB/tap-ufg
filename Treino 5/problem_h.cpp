#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const ull MAX = 1e6+100;
vector<ull> prime_list;
bitset<MAX> prime_bits;

void sieve(ull bound) {
    prime_bits.set();
    prime_bits[0] = prime_bits[1] = 0;

    for (ull i = 4; i <= bound; i += 2)
        prime_bits[i] = 0;
    
    for (ull i = 3; (i * i) <= bound; i += 2) {
        if (prime_bits[i]) {
            for (ull j = i * i; j < bound; j += i)
                prime_bits[j] = 0;
        }
    }
    
    for (ull i = 2; i <= bound; i++) 
        if (prime_bits[i]) prime_list.push_back(i);
}

bool is_prime(ull number) {
    if (number < MAX) 
        return (bool) prime_bits[number];

    for (ull i = 0, size = prime_list.size(); i < size; i++)
        if (number % prime_list[i] == 0) return false;

    return true;
}

ull power(ull a, ull b) {
    ull pow = 1;
    while (b--) pow *= a;
    return pow;
}

bool is_scary_prime(ull p) {
    ull aux;
    unsigned int d;

    if (!is_prime(p) || to_string(p).find('0') != string::npos)
        return false;

    while (p > 10) {
        aux = p;
        d = 0;
        while (aux > 10) {
            aux /= 10;
            d++;
        }
        p -= aux * power(10, d);
        if (!is_prime(p)) return false;
    }

    return is_prime(p);
}

int main() {
    ull n, t, k, index;
    const ull max_n = 1e6+10;
    vector<ull> total_scary_primes;
    sieve(MAX - 1);

    total_scary_primes.resize(max_n);

    index = k = 0;
    for (auto prime: prime_list) {
        for (ull i = index; i < prime; i++)
            total_scary_primes[i] = k;
        if (is_scary_prime(prime)) k++;
        index = prime;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << total_scary_primes[n] << '\n';
    }

    return 0;
}