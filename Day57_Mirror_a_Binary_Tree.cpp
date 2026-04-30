#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void mirrorTree(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    mirrorTree(root);
    preorder(root);
    return 0;
}
