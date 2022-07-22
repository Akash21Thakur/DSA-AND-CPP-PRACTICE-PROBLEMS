//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long n, long long int k)
{
    queue<long long> q;

    // first window
    for (long long i = 0; i < k; i++)
    {
        if (A[i] < 0)
            q.push(A[i]);
    }
    vector<long long> ans;
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(q.front());

    for (long long i = k; i < n; i++)
    {
        if (A[i - k] < 0)
            q.pop();
        if (A[i] < 0)
            q.push(A[i]);

        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(q.front());
    }
    return ans;
}