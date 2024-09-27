#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    unsigned int num_vertices, num_edges, vertex_1, vertex_2, counter = 0;
    map<unsigned int, unsigned int> vertex_degree;
    map<unsigned int, vector<unsigned int>> graph;

    cin >> num_vertices >> num_edges;

    if (num_vertices - num_edges != 1) {
        cout << "No\n";
        return 0;
    }

    while (num_edges--) {
        cin >> vertex_1 >> vertex_2;
        vertex_degree[vertex_1]++;
        vertex_degree[vertex_2]++;
        graph[vertex_1].push_back(vertex_2);
        graph[vertex_2].push_back(vertex_1);
    }
    
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
