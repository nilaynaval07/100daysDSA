#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);

    cout << LCA(root, 10, 30)->data;
}
