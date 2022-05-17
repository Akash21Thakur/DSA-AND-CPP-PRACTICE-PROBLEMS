// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (!head or !head->next)
            return head;

        node *prev = NULL, *curr = head, *temp;
        node *cur_batch_end = head;

        // first batch
        // to find the head
        for (int i = 0; i < k and curr; i++)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // incase k>size of list
        if (curr == NULL)
            return prev;

        // gives the new_head to be returned
        node *new_head = prev;

        // used to link prev_batch with the current batch
        node *prev_batch_end;

        // TIME: O(n)
        while (curr)
        {
            prev = NULL;
            prev_batch_end = cur_batch_end;
            cur_batch_end = curr;

            // for each batch
            // will also account in case last batch having less than k element
            for (int i = 0; i < k and curr; i++)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // linking
            prev_batch_end->next = prev;
        }

        return new_head;
    }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends