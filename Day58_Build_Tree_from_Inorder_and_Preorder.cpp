#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR, unordered_map<int, int>& pos) {
    if (preL > preR) return nullptr;
    Node* root = new Node(preorder[preL]);
    int mid = pos[root->data];
    int leftSize = mid - inL;
    root->left = build(preorder, preL + 1, preL + leftSize, inorder, inL, mid - 1, pos);
    root->right = build(preorder, preL + leftSize + 1, preR, inorder, mid + 1, inR, pos);
    return root;
}

Node* buildTree(vector<int> preorder, vector<int> inorder) {
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); i++) pos[inorder[i]] = i;
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, pos);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder = {4, 2, 5, 1, 3};
    postorder(buildTree(preorder, inorder));
    return 0;
}
