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

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
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

// SEARCH ELEMENT IN THE LIST
bool searchData(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

bool searchRec(Node *head, int key)
{
    if (!head)
        return false;
    if (head->data == key)
        return true;
    return searchRec(head->next, key);
}

// taking user input
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

// REVERSE LIST
void reverseList(Node *&head)
{
    if (!head or !head->next)
        return;
    Node *curr = head, *prev = NULL;

    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

// REVERSE LIST RECURSIVE
Node *reverseListRec(Node *head)
{
    if (!head->next or !head)
        return head;

    Node *shead = reverseListRec(head->next);

    // Node *temp = shead;
    // while (temp->next)
    //     temp = temp->next;

    // FINDING TEMP CAN BE FURTHER MINIMIZED AS:
    Node *temp = head->next;

    head->next = NULL;
    temp->next = head;
    return shead;
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

int main()
{
    // Node *head = takeInput();
    // cout << head;

    // // CASCADING OF operator
    // // operator overloading
    // // 1. <<
    // Node *h1 = takeInput();
    // Node *h2 = takeInput();
    // cout << h1 << h2 << endl;

    // // 2. >>
    // Node *h1;
    // Node *h2;
    // cin >> h1 >> h2;
    // cout << h1 << h2;

    Node *head;
    cin >> head;
    cout << "Before Reversing : " << head;
    head = reverseListRec(head);
    cout << "After reversing : " << head;

    // cout << "Middle data : " << findMid(head)->data << endl;

    // cout << "LIST : " << head;
    // cout << "Enter the value of k ";
    // int k;
    // cin >> k;
    // kthFromEnd(head, k);

    // printList(head);
}