#include <iostream>
using namespace std;

class Queue
{
    int size, rear, front;
    int *arr;

public:
    Queue(int size = 5)
    {
        this->size = size;
        rear = front = -1;
        arr = new int[size];
    }

    void enqueue(int d);
    int dequeue();
    void displayQueue();
};

void Queue ::enqueue(int d)
{
    // check if array is full
    if ((rear == size - 1 and front == 0) or (rear == (front - 1) % (size - 1)))
    {
        cout << "Queue is Full\n";
    }
    else if (front == -1)
    {
        rear = front = 0;
        arr[rear] = d;
    }
    else if (rear == size - 1 and front != 0)
    {
        rear = 0;
        arr[rear] = d;
    }
    else
    {
        rear++;
        arr[rear] = d;
    }
}

int Queue::dequeue()
{
    // if already empty
    if (front == -1)
    {
        cout << "Queue Empty \n";
        return -1;
    }
    int ans = arr[front];
    if (front == rear)
    {
        rear = front = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;
    return ans;
}

void Queue::displayQueue()
{
    if (front == -1)
    {
        cout << "Queue Empty !";
    }
    cout << "Queue Elements : \n";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(3);
    q.displayQueue();
}