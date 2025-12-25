#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

const int maxSize = 5;
class Queue
{

    int arr[maxSize];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isfull()
    {
        if (rear == maxSize - 1 && front == 0)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int d)
    {
        if ((rear + 1) % maxSize == front)
        {
            cout << "Queue Overflow " << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }
        arr[rear] = d;
    }

    int dequeue()
    {
        // cout << "front : " << front << endl;
        // cout << "rear : " << rear << endl;
        if (front == -1)
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int x = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }

        return x;
    }

    void print()
    {
        cout << "Full Queue : ";
        for (int i = 0; i < maxSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    // q1.enqueue(60);

    q1.print();
    cout << q1.dequeue() << endl;

    q1.enqueue(60);
    q1.print();

    cout << q1.dequeue() << endl;
    return 0;
}