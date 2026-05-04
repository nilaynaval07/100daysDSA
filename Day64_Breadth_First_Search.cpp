#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 4}, {1}, {2}};
    bfs(0, adj);
    return 0;
}
