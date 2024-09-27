#include <iostream>
#include <map>

using namespace std;

int main() {
    unsigned long num_queries, x;
    short query;
    map<int, int> bag;

    cin >> num_queries;

    while (num_queries--) {
        cin >> query;
        switch (query) {
            case 1:
                cin >> x;
                bag[x]++;
                break;

            case 2:
                cin >> x;
                bag[x]--;
                if (bag[x] == 0) bag.erase(x);
                break;

            case 3:
                cout << bag.size() << "\n";
                break;
            
            default:
                break;
        }
    }

    return 0;
}