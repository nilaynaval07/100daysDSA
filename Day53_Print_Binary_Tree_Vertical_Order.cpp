#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalOrder(Node* root) {
    map<int, vector<int>> columns;
    queue<pair<Node*, int>> q;
    if (root) q.push(make_pair(root, 0));
    while (!q.empty()) {
        Node* node = q.front().first;
        int col = q.front().second;
        q.pop();
        columns[col].push_back(node->data);
        if (node->left) q.push(make_pair(node->left, col - 1));
        if (node->right) q.push(make_pair(node->right, col + 1));
    }
    vector<vector<int>> result;
    for (map<int, vector<int>>::iterator it = columns.begin(); it != columns.end(); ++it) {
        result.push_back(it->second);
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    for (auto& col : verticalOrder(root)) {
        for (int x : col) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
