#include <iostream>
using namespace std;

class CircularQueue {
    int *arr, front, rear, size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            cout << "Overflow\n";
            return;
        }

        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    int peek() {
        if (front == -1) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    cout << q.peek();
}
