#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

// Temporary code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<vector<int>> matrix;
    vector<int> sorted, middle_nums;

    cin >> n;
    matrix.resize(n), middle_nums.resize(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        matrix[i][0] = matrix[0][i] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) 
            matrix[i][j] = matrix[i][0] * matrix[0][j];
    }

    print_matrix(matrix);
    cout << '\n';

    for (int i = 0; i < n; i++)
        middle_nums[i] = matrix[i][n / 2];

    sort(middle_nums.begin(), middle_nums.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            sorted.push_back(matrix[i][j]);
    }

    sort(sorted.begin(), sorted.end());
    for (auto a : sorted)
        cout << a << ' ';
    cout << '\n';

    cout << "\nmiddle of sorted = " << sorted[(n * n)/2] << '\n' << '\n';

    for (auto a : middle_nums)
        cout << a << ' ';
    cout << '\n';

    cout << "\nmiddle of middle_nums = " << middle_nums[n / 2] << '\n';


    cout << '\n';

    return 0;
}