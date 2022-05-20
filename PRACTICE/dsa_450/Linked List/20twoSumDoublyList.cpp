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

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void twoSum(Node *head, int sum)
{
    if (!head or !head->next)
        return;

    Node *left = head;
    Node *right = head;

    while (right->next)
        right = right->next;

    int flag = 0;
    while (left != right and right->next != left)
    {
        if ((left->data + right->data) < sum)
            left = left->next;
        else if ((left->data + right->data) > sum)
            right = right->prev;
        else
        {
            cout << left->data << " " << right->data << endl;
            left = left->next;
            right = right->next;
            flag = 1;
        }
    }
    if (!flag)
        cout << "Pair not found\n";
}

int main()
{
    Node *head = NULL;
    insert(head, 0);
    insert(head, 5);
    insert(head, 10);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);
    insert(head, 40);

    twoSum(head, 35);
}