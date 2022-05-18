// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
    Node *findMid(Node *head)
    {
        if (!head or !head->next)
            return head;
        Node *slow = head, *fast = head->next;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *mergeTwoSortedList(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        Node *dummy = new Node(-1);
        Node *temp = dummy;

        while (a and b)
        {
            if (a->data < b->data)
            {
                temp->next = a;
                temp = temp->next;
                a = a->next;
            }
            else
            {
                temp->next = b;
                temp = temp->next;
                b = b->next;
            }
        }
        if (a)
            temp->next = a;
        if (b)
            temp->next = b;

        return dummy->next;
    }

public:
    // Function to sort the given linked list using Merge Sort.

    // 1. find mid
    // 2.split into constituent nodes
    // 3. merge all

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
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends