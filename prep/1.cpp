#include <iostream>
using namespace std;

//LL from scratch
class node
{

public:
    int val;
    node *next;
    node(int d)
    {
        val = d;
        next = NULL;
    }
};

void insert(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new node(d);
}

void print(node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    node *head = NULL;
    insert(head, 5);
    insert(head, 6);
    insert(head, 8);

    print(head);
}