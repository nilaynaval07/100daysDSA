#include <bits/stdc++.h>
using namespace std;

int primMST(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size(), total = 0;
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += w;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (!inMST[v]) pq.push({weight, v});
        }
    }
    return total;
}

int main() {
    vector<vector<pair<int, int>>> adj(4);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);
    cout << primMST(adj);
    return 0;
}
