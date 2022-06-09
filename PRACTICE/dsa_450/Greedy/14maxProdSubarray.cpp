// { Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution
{
public:
    long long int findMaxProduct(vector<int> &a, int n)
    {
        long long int prod = 1;
        if (n == 1)
            return a[0];
        int mxNeg = INT_MIN, neg = 0, zeros = 0;
        // count -ve ,zeros and max_neg
        for (int i = 0; i < n; i++)
        {
            // if zero than no need to update prod
            if (a[i] == 0)
            {
                zeros++;
                continue;
            }

            if (a[i] < 0)
            {
                mxNeg = max(mxNeg, a[i]);
                neg++;
            }

            prod = (prod * a[i]) % mod;
        }

        // check if all zeros
        if (zeros == n)
            return 0;

        // if one neG and all zeros
        if (neg == 1 and zeros > 0 and neg + zeros == n)
            return 0;

        // if odd number of neg. than mxNeg is not multiplied to prod
        if (neg & 1)
            prod /= mxNeg;

        return prod;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends