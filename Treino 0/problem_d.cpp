#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 100

using namespace std;

int check(string str, vector<string> string_set) {
    int size = string_set.size();
    for (int i = 0; i < size; i++) {
        if (str.compare(string_set[i]) == 0) return 0;
    }
    return 1;
}

int main() {
    int str_lenght, size, counter = 0;
    string str, temp;
    vector<string> string_set;

    cin >> str;
    str_lenght = str.length();

    for (size = 1; size <= str_lenght; size++) {
        for (int i = 0; i < str_lenght; i++) {
            if (i + size > str_lenght)
                break;
            temp = str.substr(i, size);
            if (check(temp, string_set)) counter++;
            string_set.push_back(temp);
        }
        string_set.clear();
    }

    cout << counter;

    cout << endl;

    return 0;
}
