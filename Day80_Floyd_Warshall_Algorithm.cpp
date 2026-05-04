#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < 1e8 && dist[k][j] < 1e8) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main() {
    const int INF = 1e8;
    vector<vector<int>> graph = {{0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};
    for (auto& row : floydWarshall(graph)) {
        for (int d : row) cout << (d == INF ? -1 : d) << ' ';
        cout << '\n';
    }
    return 0;
}
