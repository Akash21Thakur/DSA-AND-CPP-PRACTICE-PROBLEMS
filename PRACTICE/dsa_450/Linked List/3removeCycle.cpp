// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

// } Driver Code Ends
/*


structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
// #include<unordered_map>
class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes

        // METHOD-1  hashmap  Space: O(n)
        /*
        unordered_map<Node*,int> mp;
         mp[head]=1;
         Node*prev=head,*curr=head->next;

         while(curr)
         {
             if(!mp[curr])
             {
                 mp[curr]=1;
                 prev=curr;
                 curr=curr->next;
             }
             else
             {
                 prev->next=NULL;
                 return;
             }
         }
         */
        // METHOD-2  HARE-TORTOISE METHOD
        // REF: CODE LIBRARY
        // algo :
        //  1. move slow and fast till they match
        //  2. other loop...move slow and fast 1 step..till their next becomes equal
        //  3. fast->next=NULL
        //  --> NOTE : when slow and fast meet at starting point...just move the fast till its next becomes equal to slow
        // fast->next=NULL;

        Node *slow = head, *fast = head;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }
        if (!fast or !fast->next)
            return;

        slow = head;

        // fast==slow==head
        if (fast == head)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
        }

        // MOVE BOTH TILL BOTH NEXT ARE EQUAL
        else
        {
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
            fast->next = NULL;
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
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
// } Driver Code Ends