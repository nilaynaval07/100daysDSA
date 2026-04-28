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

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << countLeaves(root);
}
