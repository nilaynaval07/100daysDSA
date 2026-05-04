#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int node, const vector<vector<int>>& adj, vector<int>& state) {
    state[node] = 1;
    for (int next : adj[node]) {
        if (state[next] == 1) return true;
        if (state[next] == 0 && dfsCycle(next, adj, state)) return true;
    }
    state[node] = 2;
    return false;
}

bool hasDirectedCycle(const vector<vector<int>>& adj) {
    vector<int> state(adj.size(), 0);
    for (int i = 0; i < (int)adj.size(); i++) {
        if (state[i] == 0 && dfsCycle(i, adj, state)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1}, {2}, {0}, {4}, {}};
    cout << (hasDirectedCycle(adj) ? "Cycle Found" : "No Cycle");
    return 0;
}
