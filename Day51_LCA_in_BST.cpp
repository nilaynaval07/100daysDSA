#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

Node* lcaBST(Node* root, int a, int b) {
    while (root) {
        if (a < root->data && b < root->data) root = root->left;
        else if (a > root->data && b > root->data) root = root->right;
        else return root;
    }
    return nullptr;
}

int main() {
    Node* root = nullptr;
    for (int x : {20, 10, 30, 5, 15, 25, 35}) root = insert(root, x);
    Node* ans = lcaBST(root, 5, 15);
    if (ans) cout << ans->data;
    return 0;
}
