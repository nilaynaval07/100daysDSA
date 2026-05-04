#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << ' ';
    for (int next : adj[node]) {
        if (!visited[next]) dfs(next, adj, visited);
    }
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 4}, {1}, {2}};
    vector<bool> visited(adj.size(), false);
    dfs(0, adj, visited);
    return 0;
}
