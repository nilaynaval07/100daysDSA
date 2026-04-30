#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int main() {
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    Node* root = nullptr;
    for (int value : values) root = insert(root, value);
    inorder(root);
    return 0;
}
