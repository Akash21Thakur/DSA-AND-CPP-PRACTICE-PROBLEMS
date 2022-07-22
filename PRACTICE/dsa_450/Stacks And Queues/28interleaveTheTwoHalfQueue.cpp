#include <iostream>
#include <queue>
#include <stack>

using namespace std;
// STEPS :
// 1. push 1st half in stack
// 2. enqueue the stack element.
// 3. dequeue and enqueue the queue 1st half
// 4. 1st half again to queue and pop from queue.
// 5. alernate the stack and queue...to get the desired result

queue<int> interleaveQ(queue<int> &q)
{
    // size should be even
    stack<int> s;
    int half = q.size() / 2;
    // 1
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // 2
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // 3
    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // 4
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // 5
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleaveQ(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}