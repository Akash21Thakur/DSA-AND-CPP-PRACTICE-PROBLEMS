// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// c

#define MAX_CHAR 256

struct node
{
    char a;
    struct node *next, *prev;
};

void appendNode(struct node **head_ref, struct node **tail_ref, char x)
{
    node *temp = new node;
    temp->a = x;
    temp->next = temp->prev = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}

void removeNode(struct node **head_ref, struct node **tail_ref, struct node *temp)
{
    if (*head_ref == NULL)
        return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // inDLL[x] contains pointer to a DLL node if x is present
        // in DLL. If x is not present, then inDLL[x] is NULL
        node *inDLL[MAX_CHAR];

        // repeated[x] is true if x is repeated two or more times. If x is not seen so far or x is seen only
        // once. then repeated[x] is false
        bool repeated[MAX_CHAR];

        string ans;

        struct node *head = NULL, *tail = NULL;

        // Initialize the above two arrays
        for (int i = 0; i < MAX_CHAR; i++)
        {
            inDLL[i] = NULL;
            repeated[i] = false;
        }

        for (int i = 0; i < A.length(); i++)
        {
            char x = A[i];

            // We process this character only if it has not
            // occurred or occurred only once. repeated[x] is
            // true if x is repeated twice or more.s
            if (!repeated[x])
            {
                // If the character is not in DLL, then add this
                // at the end of DLL.
                if (inDLL[x] == NULL)
                {
                    appendNode(&head, &tail, x);
                    inDLL[x] = tail;
                }
                // Otherwise remove this character from DLL
                else
                {
                    removeNode(&head, &tail, inDLL[x]);
                    inDLL[x] = NULL;
                    repeated[x] = true; // Also mark it as repeated
                }
            }

            // if head..,than its data is ans_character
            if (head)
                ans.push_back(head->a);
            else
                ans.push_back('#');
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends