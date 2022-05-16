// #include<bitstdc++.h>
#include <bits/stdc++.h>
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

// finding the kth element from the end
//  1. move first the fast element kth node from start
//  2. move slow and fast together till fast reaches end
//  3. slow pointer gives the required node(answer)

void kthFromEnd(Node *head, int k)
{
    Node *fast = head;

    // 1.
    for (int j = 1; j <= k and fast != NULL; j++)
        fast = fast->next;

    if (fast == NULL)
    {
        cout << "K EXCEEDS THE LIST SIZE" << endl;
        return;
    }

    Node *slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->data << endl;
}
