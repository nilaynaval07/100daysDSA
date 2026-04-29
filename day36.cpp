#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "QUEUE IS FULL" << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }

        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "queue empty" << endl;
            return;
        }

        cout << arr[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    int peek()
    {
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (front == -1)
        {
            cout << "queue empty" << endl;
            return;
        }

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}
