#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};

void insertNode(Node *head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(d);
    temp->next->next = NULL;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *findingStart(Node *&head)
{
    if (!head)
        return NULL;
    Node *slow = head, *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (!fast and !fast->next)
        return NULL;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(25);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(46);
    head->next->next->next->next = new Node(55);
    head->next->next->next->next->next = NULL;

    cout << findingStart(head)->data << endl;
}