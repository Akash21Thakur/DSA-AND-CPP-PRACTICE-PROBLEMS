// { Driver Code Starts
#include <bits/stdc++.h>

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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{

public:
    Node *reverse(Node *head)
    {
        if (!head or !head->next)
            return head;

        Node *cur = head;
        Node *prev = NULL, *nex;

        while (cur)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        // meth-1  n^2...for every value check in its right
        // meth-2 n,1...
        //  algo:
        //   1. reverse list
        //   2. traverse maintaining the maxx ...if we get new max...add to the answer list...else delete node
        //   3. reverse again
        //   ...last node will always be in the answer list
        // return head;
        // if(!head or !head>next)   return head;

        //   1. reverse list
        head = reverse(head);

        //   2. traverse maintaining the maxx ...if we get new max...add to the answer list...
        //       else delete node

        Node *ans = head;
        Node *cur = head->next;

        while (cur)
        {
            if (cur->data < ans->data)
            {

                ans->next = cur->next;
                delete cur;
            }
            else
            {
                ans = cur;
            }
            cur = cur->next;
        }

        // 3. reverse again
        head = reverse(head);

        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}
// } Driver Code Ends