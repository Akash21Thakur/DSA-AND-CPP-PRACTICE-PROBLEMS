// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        int n = x.length();
        for (int i = 0; i < n; i++)
        {
            char ch = x[i];
            if (ch == '(' or ch == '{' or ch == '[')
                stk.push(ch);
            else if (stk.empty())
                return false;
            else if ((stk.top() == '(' and ch == ')') or (stk.top() == '{' and ch == '}') or (stk.top() == '[' and ch == ']'))
                stk.pop();
            else
                return false;
        }

        if (stk.empty())
            return true;

        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends