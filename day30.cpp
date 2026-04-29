#include <iostream>
using namespace std;

struct Node {
    int coeff, power;
    Node* next;
};

void insert(Node*& head, int c, int p) {
    Node* newNode = new Node{c, p, NULL};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next) cout << " + ";
        head = head->next;
    }
}
