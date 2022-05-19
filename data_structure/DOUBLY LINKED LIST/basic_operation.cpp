#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int d)
    {
        this->data = d;
        next = NULL;
        prev = NULL;
    }
};

void insert(Node *&head, int d)
{
    if (!head)
    {
        head = new Node(d);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(d);
    temp->next->prev = temp;
}

void insertAtPos(Node *&head, int d, int p)
{
    if (p == 1)
    {
        Node *n = new Node(d);
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }
    Node *temp = head;
    for (int i = 1; i < p - 1 and temp->next; i++)
        temp = temp->next;

    if (!temp->next)
    {
        temp->next = new Node(d);
        temp->next->prev = temp;
        return;
    }
    Node *t = temp->next;
    temp->next = new Node(d);
    temp->next->next = t;
    temp->next->prev = temp;
    t->prev = temp->next;
}

void delNode(Node *&head, int p)
{
    if (p == 1)
    {
        Node *temp = head;
        // head->next = NULL;

        head = head->next;
        free(temp);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < p - 1 and temp->next; i++)
        temp = temp->next;

    if (!temp->next)
        cout << "INVALID POSITION" << endl;
    Node *t = temp->next;
    if (temp->next)
        temp->next = temp->next->next;
    if (temp->next->next)
        temp->next->next->prev = temp;
    // free(t);
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

int main()
{
    Node *head = NULL;
    insert(head, 5);
    insert(head, 15);
    insert(head, 55);
    insert(head, 56);
    insert(head, 51);
    insert(head, 53);

    print(head);
    // insertAtPos(head, 100, 7);
    delNode(head, 6);
    print(head);
}