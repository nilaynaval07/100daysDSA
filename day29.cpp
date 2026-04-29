Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    Node* temp = head;
    int len = 1;

    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head; // make circular

    k = k % len;
    int steps = len - k;

    while (steps--) {
        temp = temp->next;
    }

    Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}
