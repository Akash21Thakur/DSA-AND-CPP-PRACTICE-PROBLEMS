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

Node *takeInput()
{
    int d;
    cin >> d;
    Node *head = NULL;
    // fstream myfile;
    // myfile.open("input.txt", ios::in);
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    // myfile.close();
    return head;
}

// OPERATOR OVERLOADING
ostream &operator<<(ostream &os, Node *head)
{
    printList(head);
    return os;
}

istream &operator>>(istream &is, Node *&head)
{
    head = takeInput();
    return is;
}

// MERGE TWO Sorted LIST
Node *mergeTwoSortedList(Node *h1, Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    Node *new_head;
    Node *temp1 = h1, *temp2 = h2;
    if (temp1->data < temp2->data)
    {
        new_head = temp1;
        temp1 = temp1->next;
    }
    else
    {
        new_head = temp2;
        temp2 = temp2->next;
    }

    Node *temp = new_head;

    while (temp1 and temp2)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    if (temp1 == NULL)
        temp->next = temp2;
    if (temp2 == NULL)
        temp->next = temp1;

    return new_head;
}

// finding mid point od the list
Node *findMid(Node *head)
{
    if (!head or !head->next or !head->next->next)
        return head;
    Node *slow = head;
    Node *fast = head->next;

    while (fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// MERGE SORT
// TIME: NLOGN
Node *mergeSort(Node *head)
{
    if (!head or !head->next)
        return head;

    Node *mid = findMid(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    Node *c = mergeTwoSortedList(a, b);
    return c;
}

int main()
{
    // Node *h1, *h2;
    // cout << "list-1 : ";
    // cin >> h1;
    // cout << "list-2 : ";
    // cin >> h2;

    // Node *head = mergeTwoSortedList(h1, h2);
    // cout << "After merging : ";
    // printList(head);
    Node *head;
    cin >> head;
    cout << "Before Sort : " << head;

    head = mergeSort(head);
    cout << "After Sort : " << head;
}