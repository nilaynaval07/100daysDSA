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

bool isMirror(Node* t1, Node* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;

    return (t1->data == t2->data)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
}

bool isSymmetric(Node* root) {
    return isMirror(root, root);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    cout << isSymmetric(root);
}
