#include <iostream>
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

void zigzag(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int n = q.size();
        int arr[n];

        for (int i = 0; i < n; i++) {
            Node* node = q.front(); q.pop();

            int index = leftToRight ? i : (n - i - 1);
            arr[index] = node->data;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        leftToRight = !leftToRight;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    zigzag(root);
}
