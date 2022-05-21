
// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

    Node *sortTwoSortedList(Node *a, Node *b)
    {
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
        else
            temp->next = b;

        return dummy->next;
    }

public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        //   if(k==1)
        //      return *arr[0];

        // sort in pair starting from last two
        // arr[i]=sorted(i,i+1);
        // SO, arr[0] answer sorted list
        int i = K - 2;
        while (i >= 0)
        {
            arr[i] = sortTwoSortedList(arr[i], arr[i + 1]);
            i--;
        }
        return arr[0];
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends