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

void insertNode(Node *&head, int d)
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
    cout << endl;
}

void moveLastFirst(Node *&head)
{
    if (!head or !head->next)
        return;
    Node *temp = head;

    // stop in the second last node
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *new_head = temp->next;
    new_head->next = head;
    temp->next = NULL;
    head = new_head;
}

int main()
{
    Node *head = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        insertNode(head, d);
        cin >> d;
    }

    print(head);

    moveLastFirst(head);

    print(head);
}