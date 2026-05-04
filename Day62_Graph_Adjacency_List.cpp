#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}};
    vector<vector<int>> adj(vertices);
    for (int i = 0; i < (int)edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}
