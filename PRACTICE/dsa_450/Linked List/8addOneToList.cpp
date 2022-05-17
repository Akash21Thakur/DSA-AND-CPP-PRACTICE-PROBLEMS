// { Driver Code Starts
// Initial template for C++

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverse(Node *head)
    {
        // RECURSIVE
        //  if(!head or !head->next)
        //    return head;
        //  Node*shead=reverse(head->next);
        //  Node*temp=head->next;
        //  temp->next=head;
        //  head->next=NULL;
        //  return shead;

        // ITERATIVE
        Node *prev = NULL;
        Node *next = NULL;
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
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        if (!head)
            return head;

        // reverse to add efficiently
        head = reverse(head);

        Node *temp = head;

        // SIMPLE AS SEEMS...3 CONDITION EXPLAINED
        while (true)
        {
            if (temp->data < 9)
            {
                temp->data++;
                return reverse(head);
            }
            else if (temp->data == 9 and temp->next == NULL)
            {
                temp->data = 0;
                temp->next = new Node(1);
                return reverse(head);
            }
            else // if(temp->data==9)
            {
                temp->data = 0;
                temp = temp->next;
            }

            //     temp=temp->next;

            //     if(temp->data<9)
            // {
            //     temp->data++;
            //     return reverse(head);
            // }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends