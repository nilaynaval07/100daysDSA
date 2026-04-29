#include <iostream>
using namespace std;

class MinHeap {
    int arr[100];
    int size = 0;

    void heapifyUp(int i) {
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    void insert(int x) {
        arr[size] = x;
        heapifyUp(size);
        size++;
    }

    int getMin() {
        if (size == 0) return -1;
        return arr[0];
    }
};

int main() {
    MinHeap h;
    h.insert(30);
    h.insert(10);
    h.insert(20);
    cout << h.getMin();
}
