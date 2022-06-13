// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // sort and find the min. diff b/w  all possible ith and (i+m)th element
        sort(a.begin(), a.end());

        long long ans = INT_MAX;
        int i = 0, k = m - 1;

        while (k < n)
        {
            ans = min((a[k] - a[i]), ans);
            i++;
            k++;
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends