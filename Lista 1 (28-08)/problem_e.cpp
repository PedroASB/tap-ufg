// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100

int check(vector<int> numbers) {
    int k = 0;
    for (auto number: numbers) {
        if (number > 0) k++;
    }
    return k <= 1;
}

int main() {
    int aux, n, counter = 0;
    vector<int> numbers;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> aux;
        numbers.push_back(aux);
    }

    while (1) {
        // Ordena em ordem decrescente
        sort(numbers.begin(), numbers.end(), greater<int>());
        numbers[0]--;
        numbers[1]--;
        counter++;
        if (check(numbers))
            break;
    }

    cout << counter;

    cout << "\n";
    return 0;
}