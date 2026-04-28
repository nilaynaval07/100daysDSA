Node* deleteKey(Node* head, int key) {
    if (head == NULL) return NULL;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    return head;
}
