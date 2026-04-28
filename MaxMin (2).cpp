#include <climits>

int findMax(Node* head) {
    int mx = INT_MIN;
    while (head != NULL) {
        if (head->data > mx)
            mx = head->data;
        head = head->next;
    }
    return mx;
}

int findMin(Node* head) {
    int mn = INT_MAX;
    while (head != NULL) {
        if (head->data < mn)
            mn = head->data;
        head = head->next;
    }
    return mn;
}
