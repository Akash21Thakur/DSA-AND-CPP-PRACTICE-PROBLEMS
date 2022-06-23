// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{

    bool solve(int csum, int *a, int k, int n, int target, vector<int> &vis)
    {
        // if k-1 subsets are formed with target sum
        if (k == 1)
            return true;

        // when surrent sum exceeds
        //  if(csum>target)  return false;

        // if 1-subset found...check for other...freah start with (k-1)
        if (csum == target)
            return solve(0, a, k - 1, n, target, vis);

        for (int i = 0; i < n; i++)
        {
            // when surrent sum exceeds or already visited
            if (!vis[i] and csum + a[i] <= target)
            {
                vis[i] = 1;
                if (solve(csum + a[i], a, k, n, target, vis))
                    return true;

                // backtracking
                vis[i] = 0;
            }
        }
        return false;
    }

public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = accumulate(a, a + n, 0);
        if (k > n or sum % k != 0)
            return false;
        vector<int> vis(n, 0);
        int target = sum / k;
        return solve(0, a, k, n, target, vis);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
} // } Driver Code Ends