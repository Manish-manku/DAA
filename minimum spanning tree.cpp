#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<Edge> primMST(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<bool> visited(n, false); 
    vector<Edge> minSpanningTree;   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        if (!minSpanningTree.empty() || visited[u]) {
            minSpanningTree.push_back({u, pq.top().first});
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return minSpanningTree;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter the edges and their weights (from, to, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight}); 
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;
    vector<Edge> minSpanningTree = primMST(graph, source);

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : minSpanningTree) {
        cout << edge.to << " - " << edge.weight << endl;
    }

    return 0;
}
