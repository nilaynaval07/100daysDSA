#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}};
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));
    for (int i = 0; i < (int)edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    for (auto& row : matrix) {
        for (int value : row) cout << value << ' ';
        cout << '\n';
    }
    return 0;
}
