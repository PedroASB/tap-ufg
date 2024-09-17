#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_books, book_time, time_left, books_read = 0, max_books = 0;
    queue<int> q;

    cin >> num_books >> time_left;
    
    while(num_books--) {
        cin >> book_time;
        
        while (time_left < book_time && !q.empty()) {
            time_left += q.front();
            books_read--;
            q.pop();
        }

        if (time_left >= book_time) {
            time_left -= book_time;
            books_read++;
            q.push(book_time);
        } 
 
        if (books_read > max_books) max_books = books_read;
    }

    cout << max_books << '\n';

    return 0;
}