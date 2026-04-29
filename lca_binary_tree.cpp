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

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << LCA(root, 2, 3)->data;
}
