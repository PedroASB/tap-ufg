#include <bits/stdc++.h>

using namespace std;
const int MAX = (2 * 1e5);
typedef pair<double, pair<int, int>> Edge;
typedef pair<double, double> Point;

// Union and Find
int parent[MAX], ranking[MAX], set_size[MAX];

void init_dsu(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranking[i] = 0;
        set_size[i] = 1;
    }
}

int find(int a) {
    if (a != parent[a]) parent[a] = find(parent[a]);
    return parent[a];
}

void unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;

    if (ranking[a] < ranking[b]) {
        parent[a] = b;
        set_size[b] += set_size[a];
    }
    else if (ranking[a] > ranking[b]) {
        parent[b] = a;
        set_size[a] += set_size[b];
    }
    else {
        parent[a] = b;
        set_size[b] += set_size[a];
        ranking[b]++;
    }
}


// Graph
typedef struct graph {
    vector<Edge> edge_list;
    double total_weight = 0;
} Graph;

void add_edge(Graph graph, int v1, int v2, int weight) {
    graph.edge_list.push_back(make_pair(weight, make_pair(v1, v2)));
	graph.total_weight += weight;
}

Graph kruskal(Graph graph, int qtt_vertices) {
    Graph mst; // minimum spanning tree
    int curr_v1, curr_v2;
	double curr_weight;
    init_dsu(qtt_vertices);

	sort(graph.edge_list.begin(), graph.edge_list.end());

	for (auto edge: graph.edge_list) {
		curr_weight = edge.first;
		curr_v1 = edge.second.first;
		curr_v2 = edge.second.second;
		
		if (find(curr_v1) != find(curr_v2)) {
			unite(curr_v1, curr_v2);            
            add_edge(mst, curr_v1, curr_v2, curr_weight);
		}
	}
	
	return mst;
}

double euclidian_distance(Point a, Point b) {
    double x1, x2, y1, y2;
    x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


// Não finalizado
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    double min_total_lenght;
    vector<Point> points;
    Graph graph, mst;
    cin >> t;

    while (t--) {
        cin >> n;
        points.resize(n);
        cin >> points[0].first >> points[0].second;
        for (int i = 1; i < n; i++) {
            cin >> points[i].first >> points[i].second;
            for (int j = 0; j < i; j++) {
                add_edge(graph, j, i, euclidian_distance(points[j], points[i]));
            }
        }
        mst = kruskal(graph, n);
        min_total_lenght = 0;
        for (auto e: mst.edge_list) {
            min_total_lenght += e.first;
        }
        cout << setprecision(2) << min_total_lenght << "\n\n";
        points.clear();
    }
    
    return 0;
}