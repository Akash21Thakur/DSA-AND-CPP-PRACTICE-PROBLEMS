// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *next = NULL;
        Node *temp = head;
        while (temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        if (!first)
            return second;
        if (!second)
            return first;

        // reverse both list
        first = reverse(first);
        second = reverse(second);

        // dummy node for storing answer
        Node *dummy = new Node(-1);

        // traverse the answer list
        Node *temp = dummy;
        int carry = 0;

        // first accounts for the answer list
        while (first and second)
        {
            int sum = first->data + second->data + carry;
            first->data = sum % 10;
            temp->next = first;
            temp = first;
            carry = sum / 10;
            first = first->next;
            second = second->next;
        }

        // when the second list is exhausted
        while (first)
        {
            int sum = first->data + carry;
            first->data = sum % 10;
            temp->next = first;
            temp = first;
            carry = sum / 10;
            first = first->next;
        }

        // when the first list is exhausted

        while (second)
        {
            int sum = second->data + carry;
            second->data = sum % 10;
            temp->next = second;
            temp = second;
            carry = sum / 10;
            second = second->next;
        }

        // carry is still not zero...new node need to be created
        if (carry != 0)
            temp->next = new Node(carry);

        // reverse from dummy-> next
        dummy = reverse(dummy->next);

        return dummy;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends