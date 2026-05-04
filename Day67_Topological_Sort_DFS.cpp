#include <bits/stdc++.h>
using namespace std;

void topoDfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) topoDfs(next, adj, visited, order);
    }
    order.push_back(node);
}

vector<int> topologicalSort(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> order;
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i]) topoDfs(i, adj, visited, order);
    }
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    for (int x : topologicalSort(adj)) cout << x << ' ';
    return 0;
}
