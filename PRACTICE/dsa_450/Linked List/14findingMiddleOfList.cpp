#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int d)
    {
        this->val = d;
        next = NULL;
    }
};

// HARE_TORTOISE METHOD
ListNode *middleNode(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}