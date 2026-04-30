#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagTraversal(Node* root) {
    vector<vector<int>> answer;
    queue<Node*> q;
    if (root) q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            int index = leftToRight ? i : n - 1 - i;
            level[index] = node->data;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        answer.push_back(level);
        leftToRight = !leftToRight;
    }
    return answer;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    for (auto& level : zigzagTraversal(root)) {
        for (int x : level) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
