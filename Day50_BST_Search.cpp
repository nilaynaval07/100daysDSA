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
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

bool searchBST(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        root = key < root->data ? root->left : root->right;
    }
    return false;
}

int main() {
    Node* root = nullptr;
    for (int x : {50, 30, 70, 20, 40, 60, 80}) root = insert(root, x);
    cout << (searchBST(root, 60) ? "Found" : "Not Found");
    return 0;
}
