// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void helper(string str, int k, string &max, int idx)
    {
        if (k == 0)
            return;
        int n = str.size();
        char maxm = str[idx];
        // finding the maximum element in the remaining string
        for (int j = idx + 1; j < n; j++)
        {
            if (str[j] > maxm)
                maxm = str[j];
        }
        // if maxm changed
        if (maxm != str[idx])
            k--;

        // we need to check from behind ...as in case of more than 1 maxm...
        // swapping with last appeared will give best result
        for (int j = n - 1; j >= idx; j--)
        {
            if (str[j] == maxm)
            {

                swap(str[idx], str[j]);

                if (str.compare(max) > 0)
                    max = str;

                helper(str, k, max, idx + 1);

                // backtracking

                swap(str[idx], str[j]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string max = str;
        helper(str, k, max, 0);
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends