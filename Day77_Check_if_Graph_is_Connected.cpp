#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) dfs(next, adj, visited);
    }
}

bool isConnected(const vector<vector<int>>& adj) {
    if (adj.empty()) return true;
    vector<bool> visited(adj.size(), false);
    dfs(0, adj, visited);
    return all_of(visited.begin(), visited.end(), [](bool value) { return value; });
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0}, {1}};
    cout << (isConnected(adj) ? "Connected" : "Not Connected");
    return 0;
}
