#include <iostream>
using namespace std;

class Queue {
    int *arr, front, rear, size;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > rear) return -1;
        return arr[front];
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << q.peek();
}
