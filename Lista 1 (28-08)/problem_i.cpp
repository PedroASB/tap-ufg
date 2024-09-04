#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main() {
    unsigned int num_vertices, num_edges, vertex_1, vertex_2, counter = 0;
    map<unsigned int, unsigned int> vertex_degree;

    cin >> num_vertices >> num_edges;

    if (num_vertices - num_edges != 1) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < num_edges; i++) {
        cin >> vertex_1 >> vertex_2;
        vertex_degree[vertex_1]++;
        vertex_degree[vertex_2]++;
    }
    
    cout << "\n--------\n";
    for (int i = 1; i <= num_vertices; i++) {
        cout << vertex_degree[i] << " ";
    }
    cout << "\n--------\n";
    
    for (int i = 1; i <= num_vertices; i++) {
        if (vertex_degree[i] == 1) {
            counter++;
        } else if (vertex_degree[i] != 2) {
            cout << "No\n";
            return 0;
        }  
    }

    (counter == 2) ? cout << "Yes\n" : cout << "No\n";
    
    return 0;
}