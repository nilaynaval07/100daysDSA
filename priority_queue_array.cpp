#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size = 0;

public:
    void enqueue(int x) {
        int i = size - 1;

        while (i >= 0 && arr[i] < x) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        size++;
    }

    void dequeue() {
        if (size == 0) return;
        size--;
    }

    int peek() {
        if (size == 0) return -1;
        return arr[0];
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10);
    pq.enqueue(30);
    pq.enqueue(20);
    cout << pq.peek();
}
