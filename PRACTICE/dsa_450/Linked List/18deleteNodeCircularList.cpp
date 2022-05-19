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
    Node *temp = head;
    while (head->next != temp)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << " ";
    cout << endl;
}

void deleteNode(Node **head, int key)
{
    // if list is empty
    if (*head == NULL)
        return;

    // single node with key value
    if ((*head)->data == key and (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *prev = *head;

    // if head is the key node
    if ((*head)->data == key)
    {
        while (prev->next != *head)
            prev = prev->next;

        prev->next = (*head)->next;
        free(*head);
        *head = prev->next;
        return;
    }

    while (prev->next != (*head) and prev->next->data != key)
    {
        prev = prev->next;
    }

    if (prev->next->data == key)
    {
        Node *temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
    else
        cout << "Required KEY NOT FOUND" << endl;
}

int main()
{
    Node *head = new Node(5);

    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(25);
    head->next->next->next->next->next = head;

    print(head);

    deleteNode(&head, 5);
    print(head);
}