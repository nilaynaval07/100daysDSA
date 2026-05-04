#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) dfs(next, adj, visited);
    }
}

int countComponents(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    int components = 0;
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    vector<vector<int>> adj = {{1}, {0}, {3}, {2}, {}};
    cout << countComponents(adj);
    return 0;
}
