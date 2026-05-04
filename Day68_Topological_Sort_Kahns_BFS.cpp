#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0), order;
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return order;
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    for (int x : kahnTopologicalSort(adj)) cout << x << ' ';
    return 0;
}
