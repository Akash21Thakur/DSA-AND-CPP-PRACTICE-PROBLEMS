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
        cout << node->data << " ";
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
public:
    Node *divide(int N, Node *head)
    {
        // Node*dummy=head;
        // Node*even=dummy,*odd=NULL;
        // Node*cur=head;

        // while(cur)
        // {
        //     if(cur->data%2==0)
        //      {
        //          even->next=cur;
        //          even=even->next;

        //      }
        //      else
        //      {
        //          odd->next=cur;
        //          odd=odd->next;
        //      }
        //      cur=cur->next;
        // }

        // if(even->data==-1)
        //   return head;
        // if(odd==NULL)
        //   return head;

        // if(odd)
        //   even->next=odd;

        // return dummy->next;

        Node *dummy_even = new Node(-1);
        Node *even = dummy_even;

        Node *dummy_odd = new Node(-1);
        Node *odd = dummy_odd;

        Node *cur = head;

        while (cur)
        {
            if (cur->data % 2 == 0)
            {
                even->next = cur;
                even = even->next;
                ;
            }
            else
            {
                odd->next = cur;
                odd = odd->next;
            }
            cur = cur->next;
        }

        // end the odd node
        if (odd->next)
            odd->next = NULL;
        //   attach even with odd one
        even->next = dummy_odd->next;
        return dummy_even->next;
    }
};

// { Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends