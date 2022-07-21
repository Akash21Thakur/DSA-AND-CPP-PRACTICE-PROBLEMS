#include <iostream>
#include <stack>
using namespace std;

void insertAtEnd(stack<int> &s, int x)
{
    if (s.empty())
        s.push(x);
    else
    {
        int a = s.top();
        s.pop();
        insertAtEnd(s, x);
        s.push(a);
    }
}

int main()
{
    stack<int> s;
    insertAtEnd(s, 3);
    insertAtEnd(s, 30);
    insertAtEnd(s, 300);
    insertAtEnd(s, 3000);
    insertAtEnd(s, 30000);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}