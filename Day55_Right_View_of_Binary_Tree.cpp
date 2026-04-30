#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> rightView(Node* root) {
    vector<int> view;
    queue<Node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            if (i == n - 1) view.push_back(node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return view;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    for (int x : rightView(root)) cout << x << ' ';
    return 0;
}
