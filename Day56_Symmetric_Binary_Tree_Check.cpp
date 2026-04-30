#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool mirror(Node* a, Node* b) {
    if (!a || !b) return a == b;
    return a->data == b->data && mirror(a->left, b->right) && mirror(a->right, b->left);
}

bool isSymmetric(Node* root) {
    return !root || mirror(root->left, root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(3);
    cout << (isSymmetric(root) ? "Symmetric" : "Not Symmetric");
    return 0;
}
