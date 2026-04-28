int countOccurrences(Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}
