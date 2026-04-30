#include <iostream>
#include <map>
#include <queue>
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

void verticalOrder(Node* root) {
    if (!root) return;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        mp[hd].push_back(node->data);

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto x : mp) {
        for (int val : x.second)
            cout << val << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    verticalOrder(root);
}
