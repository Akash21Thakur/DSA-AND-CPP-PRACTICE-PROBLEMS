// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void helper(vector<vector<int>> &ans, vector<int> &v, int idx, vector<int> &A, int target)
    {

        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (idx == A.size())
        {

            return;
        }
        // pick
        if (A[idx] <= target)
        {
            v.push_back(A[idx]);
            helper(ans, v, idx, A, target - A[idx]);

            // backtracking
            v.pop_back();
        }

        // not pick
        helper(ans, v, idx + 1, A, target);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        vector<int> v;
        // take unique values from A
        vector<int> A1;
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++)
        {
            if (i < A.size() - 1 and A[i] == A[i + 1])
                continue;
            A1.push_back(A[i]);
        }

        vector<vector<int>> ans;
        helper(ans, v, 0, A1, B);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
} // } Driver Code Ends