#include <iostream>
#include <fstream>
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

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// count number of nodes
int countNodes(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

// insert at given position
void insertAtPos(Node *&head, int data, int pos)
{
    if (!head or pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *n = new Node(data);
    Node *temp = head;
    int j = 1;
    while (j < pos - 1 and temp->next)
    {
        j++;
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = n;
    n->next = temp2;

    /*
    if (pos > countNodes(head))
    {

        while (temp->next)
            temp = temp->next;
        temp->next = n;
        return;
    }

    int j = 1;
    Node *temp = head;
    while (j < pos - 1)
    {
        temp = temp->next;
        j++;
    }
    Node *n = new Node(data);
    Node *temp2 = temp->next;
    temp->next = n;
    n->next = temp2;
    */
}

// INSERT AT TAIL
void insertAtTail(Node *&head, int data)
{
    if (!head)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new Node(data);
}

// DELETE HEAD
void delhead(Node *&head)
{
    if (!head)
        return;

    Node *temp = head->next; // temp --->local
    delete head;
    head = temp;
}

// DELETE NODE AT POSITION
void delAtPos(Node *&head, int p)
{
    if (p == 1)
    {
        delhead(head);
        return;
    }
    if (p > countNodes(head))
        return;
    int j = 1;
    Node *temp = head;
    while (j < p - 1)
    {
        j++;
        temp = temp->next;
    }
    if (!temp->next)
        return;
    Node *temp2 = temp->next->next;
    temp->next->next = NULL;
    delete temp->next;
    temp->next = temp2;
}

// int main()
// {
//     Node *head = NULL;
//     insertAtHead(head, 5);
//     insertAtHead(head, 15);
//     insertAtHead(head, 25);
//     insertAtHead(head, 35);
//     insertAtHead(head, 45);
//     insertAtHead(head, 55);
//     // cout<<"AKASH THAKUR"<<endl;
//     printList(head);
//     // insertAtPos(head, 25, 2);
//     // printList(head);

//     // cout << searchData(head, 225) << endl;
//     // cout << searchRec(head, 251) << endl;
//     // delAtPos(head, 6);
//     // reverseList(head);
//     // printList(head);
// }