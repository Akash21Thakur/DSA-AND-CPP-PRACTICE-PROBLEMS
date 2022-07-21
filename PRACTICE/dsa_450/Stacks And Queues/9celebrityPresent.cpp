//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool knows(int a, int b, vector<vector<int>> &M)
    {
        return M[a][b];
    }

    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();

            if (knows(i, j, M))
                st.push(j);
            else
                st.push(i);
        }

        // potential candidate
        int c = st.top();
        // need to check is so
        for (int i = 0; i < n; i++)
        {
            if ((i != c) and (knows(c, i, M) == 1 or knows(i, c, M) == 0))
                return -1;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends