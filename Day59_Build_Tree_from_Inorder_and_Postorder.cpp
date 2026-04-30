#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int postL, int postR, unordered_map<int, int>& pos) {
    if (inL > inR) return nullptr;
    Node* root = new Node(postorder[postR]);
    int mid = pos[root->data];
    int leftSize = mid - inL;
    root->left = build(inorder, inL, mid - 1, postorder, postL, postL + leftSize - 1, pos);
    root->right = build(inorder, mid + 1, inR, postorder, postL + leftSize, postR - 1, pos);
    return root;
}

Node* buildTree(vector<int> inorder, vector<int> postorder) {
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); i++) pos[inorder[i]] = i;
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, pos);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};
    preorder(buildTree(inorder, postorder));
    return 0;
}
