#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != head and fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    if (fast->next == head)
        fast->next = *head2_ref;
    else
        fast->next->next = *head2_ref;
}