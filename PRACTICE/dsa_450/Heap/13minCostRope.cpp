// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        // add min_2 to ans and push it to minHeap
        long long ans = 0;
        while (pq.size() != 1)
        {
            long long int mini1 = pq.top();
            pq.pop();
            long long int mini2 = pq.top();
            pq.pop();

            ans += (mini1 + mini2);
            pq.push(mini1 + mini2);
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
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends