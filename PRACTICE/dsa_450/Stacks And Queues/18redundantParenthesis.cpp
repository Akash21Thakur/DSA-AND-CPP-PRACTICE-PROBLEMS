//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st; // will push ( and operators
        // if ) has immediate (  return true;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '+' or ch == '-' or ch == '/' or ch == '*' or ch == '(')
                st.push(ch);
            else if (ch == ')')
            {
                // incase immediate '('
                if (st.top() == '(')
                    return true;
                while (st.top() == '+' or st.top() == '-' or st.top() == '/' or st.top() == '*')
                    st.pop();
                // last is '('
                st.pop();
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends