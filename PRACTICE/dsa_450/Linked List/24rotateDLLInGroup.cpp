#include <iostream>
#include <queue>
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

Node *rotateByKRecursive(Node *head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr and count < k)
    {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }

    if (count >= k)
    {
        Node *rest = rotateByKRecursive(curr, k);
        head->next = rest;
        if (rest)
            rest->prev = head;
    }
    return newHead;
}

Node *rotateIterative(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *st = head;
    Node *rotatedEnd = NULL;
    Node *ans_head = NULL;

    while (st != NULL)
    {
        int count = 1;
        Node *curr = st;
        Node *prev = NULL, *temp = NULL;
        while (curr and count <= k)
        {
            temp = curr->next;
            curr->next = prev;
            curr->prev = temp;
            prev = curr;
            curr = curr->prev;
            count++;
        }

        // answer head...first group rotated head
        if (ans_head == NULL)
            ans_head = prev;

        // for 1st group
        if (rotatedEnd == NULL)
            rotatedEnd = st;
        // for rest group..linking is important
        else
        {
            rotatedEnd->next = prev;
            prev->prev = rotatedEnd;

            rotatedEnd = st;
        }
        st = curr;
    }
    return ans_head;
}

int main()
{
    Node *head = NULL;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        cin >> temp;
        insert(head, temp);
    }
    // print(head);
    head = rotateIterative(head, 5);
    print(head);
    // head = rotateByKRecursive(head, 5);
    // print(head);
}