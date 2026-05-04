#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int source, const vector<vector<pair<int, int>>>& adj) {
    const int INF = 1e9;
    vector<int> dist(adj.size(), INF);
    set<pair<int, int>> active;
    dist[source] = 0;
    active.insert({0, source});
    while (!active.empty()) {
        int d = active.begin()->first;
        int u = active.begin()->second;
        active.erase(active.begin());
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (d + w < dist[v]) {
                active.erase({dist[v], v});
                dist[v] = d + w;
                active.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pair<int, int>>> adj(4);
    adj[0] = {{1, 1}, {2, 4}};
    adj[1] = {{2, 2}, {3, 6}};
    adj[2] = {{3, 3}};
    for (int d : shortestPath(0, adj)) cout << d << ' ';
    return 0;
}
