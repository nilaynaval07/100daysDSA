#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* lcaBinaryTree(Node* root, int a, int b) {
    if (!root || root->data == a || root->data == b) return root;
    Node* left = lcaBinaryTree(root->left, a, b);
    Node* right = lcaBinaryTree(root->right, a, b);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Node* ans = lcaBinaryTree(root, 4, 5);
    if (ans) cout << ans->data;
    return 0;
}
