//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    // remove first k element and add to stack
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // empty the stack...reverses the k element but adds to rear end
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // remove the n-k element from the front side of the q...and add at end
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}