#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(const vector<int>& heap) {
    int n = heap.size();
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && heap[i] > heap[left]) return false;
        if (right < n && heap[i] > heap[right]) return false;
    }
    return true;
}

int main() {
    vector<int> heap = {1, 3, 5, 7, 9, 8};
    cout << (isMinHeap(heap) ? "Valid Min-Heap" : "Invalid Min-Heap");
    return 0;
}
