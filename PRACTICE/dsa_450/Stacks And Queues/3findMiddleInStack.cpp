#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        next = prev = NULL;
    }
};

Node *dummy = new Node(-1);
Node *head = dummy;
Node *middle = dummy;
int count = 0;

// move linked list to opposite direction...try in copy for constant operation,also head shift with every push
void push(int x)
{
    Node *curr = new Node(x);
    curr->prev = head;
    curr->next = NULL;
    head->next = curr;
    head = curr;
    count++;
    if (count == 1)
        middle = curr;
    // if 6 element ...middle is 4th element
    else if (count % 2 == 0)
    {
        middle = middle->next;
    }
}

int pop()
{
    if (count == 0)
    {
        cout << "Stack is empty ";
        return -1;
    }

    Node *temp = head;
    int x = temp->data;
    head = head->prev;
    if (head != NULL)
        head->next = NULL;
    count--;
    if (count & 1)
    {
        middle = middle->prev;
    }
    free(temp);
    return x;
}

int findMiddle()
{
    if (count == 0)
    {
        cout << "EMPTY ";
        return -1;
    }
    return middle->data;
}

int main()
{
    cout << pop() << endl;
    cout << findMiddle() << endl;
    push(1);
    push(2);
    push(3);
    push(30);
    // cout << findMiddle() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << findMiddle() << endl;

    push(10);
    cout << findMiddle() << endl;
}