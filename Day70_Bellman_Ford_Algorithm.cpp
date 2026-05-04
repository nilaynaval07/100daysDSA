#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int vertices, int source, const vector<tuple<int, int, int>>& edges) {
    const int INF = 1e9;
    vector<int> dist(vertices, INF);
    dist[source] = 0;
    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < (int)edges.size(); j++) {
            int u, v, w;
            tie(u, v, w) = edges[j];
            if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    for (int j = 0; j < (int)edges.size(); j++) {
        int u, v, w;
        tie(u, v, w) = edges[j];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            throw runtime_error("Negative weight cycle detected");
        }
    }
    return dist;
}

int main() {
    vector<tuple<int, int, int>> edges = {{0, 1, 5}, {0, 2, 4}, {1, 3, 3}, {2, 1, -2}, {3, 2, 2}};
    for (int d : bellmanFord(4, 0, edges)) cout << d << ' ';
    return 0;
}
