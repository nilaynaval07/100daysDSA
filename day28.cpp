#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createCircular(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node{arr[0], NULL};
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new Node{arr[i], NULL};
        temp = temp->next;
    }

    temp->next = head; // make circular
    return head;
}

void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
