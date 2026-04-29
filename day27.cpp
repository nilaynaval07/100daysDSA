Node* getIntersection(Node* head1, Node* head2) {
    Node* a = head1;
    Node* b = head2;

    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    return a; // intersection node or NULL
}
