#include <iostream>
#include <vector>

#define MAX_SIZE 5
using namespace std;

class Queue
{
    int *arr;
    int front, rear, curr_size, max_size;

public:
    Queue(int size = 5)
    {
        arr = new int[size];
        max_size = size;
        front = 0;
        rear = size - 1;
        curr_size = 0;
    }

    bool isFull()
    {
        return (curr_size == max_size);
    }

    bool isEmpty()
    {
        return curr_size == 0;
    }

    void push(int x)
    {
        if (!isFull())
        {
            rear = (rear + 1) % max_size;
            arr[rear] = x;
            curr_size++;
        }
        else
            cout << "ALREADY FULL" << endl;
    }

    int front_element()
    {
        if (!isEmpty())
            return arr[front];
        else
        {
            cout << "EMPTY !!!";
            return -1;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            front = (front + 1) % max_size;
            curr_size--;
        }
        else
            cout << "ALREADY EMPTY";
    }

    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front_element() << endl;
    q.pop();
    cout << q.front_element() << endl;
    q.pop();
    cout << q.front_element() << endl;
    q.pop();
    cout << q.front_element() << endl;
    q.push(50);
    cout << q.front_element() << endl;
}