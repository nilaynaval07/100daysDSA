#include <iostream>
using namespace std;

class Deque {
    int arr[100];
    int front = -1, rear = -1, size = 100;

public:
    void pushFront(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) return;

        if (front == -1) front = rear = 0;
        else if (front == 0) front = size - 1;
        else front--;

        arr[front] = x;
    }

    void pushBack(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) return;

        if (front == -1) front = rear = 0;
        else if (rear == size - 1) rear = 0;
        else rear++;

        arr[rear] = x;
    }

    void popFront() {
        if (front == -1) return;

        if (front == rear) front = rear = -1;
        else if (front == size - 1) front = 0;
        else front++;
    }

    int getFront() {
        if (front == -1) return -1;
        return arr[front];
    }
};

int main() {
    Deque dq;
    dq.pushFront(10);
    dq.pushBack(20);
    cout << dq.getFront();
}
