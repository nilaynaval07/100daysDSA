#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int node, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            if (dfsCycle(next, node, adj, visited)) return true;
        } else if (next != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i] && dfsCycle(i, -1, adj, visited)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1}, {4}, {3}};
    cout << (hasCycle(adj) ? "Cycle Found" : "No Cycle");
    return 0;
}
