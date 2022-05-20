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
    if (!head or p <= 0)
        return;

    Node *temp = head;
    int i;
    for (i = 1; i < p and temp->next; i++)
        temp = temp->next;

    // last node to be inserted (p>size(list))
    if (temp->next == NULL and i != p)
    {
        temp->next = new Node(d);
        temp->next->prev = temp;
        return;
    }

    // if p==1
    if (temp == head)
    {
        temp->prev = new Node(d);
        temp->prev->next = head;
        head = temp->prev;
        return;
    }

    // for all other nodes
    Node *n = new Node(d);
    Node *t = temp->prev;
    temp->prev = n;
    n->next = temp;
    n->prev = t;
    t->next = n;
}

void delNode(Node **head, Node *del)
{
    if (!*head or !del)
        return;

    // first node
    if (*head == del)
        *head = del->next;

    // change next if not the last node
    if (del->next != NULL)
        del->next->prev = del->prev;

    // change the prev if not the first node
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void delNodeAtPos(Node *&head, int p)
{
    if (!head or p <= 0)
        return;
    Node *temp = head;
    int i;
    for (i = 1; i < p and temp; i++)
        temp = temp->next;

    // p>size
    if (!temp)
    {
        cout << "INVALID POSITION" << endl;
        return;
    }

    delNode(&head, temp);
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
    insertAtPos(head, 100, 70);
    // delNodeAtPos(head, 70);
    print(head);
}