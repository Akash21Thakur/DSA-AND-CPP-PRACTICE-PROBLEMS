#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};

bool isCircular(struct Node *head)
{
    if (!head)
        return true;
    struct Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        if (temp == head)
            return true;
    }
    return false;
}