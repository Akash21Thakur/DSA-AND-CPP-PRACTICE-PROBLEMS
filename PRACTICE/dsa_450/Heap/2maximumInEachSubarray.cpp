//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // if(k>n)
        //   return {};
        priority_queue<pair<int, int>> pq;
        // first window
        for (int i = 0; i < k; i++)
            pq.push({arr[i], i});
        vector<int> ans;
        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({arr[i], i}); // push_current

            // remove if top.idx is less than current k subarray size
            while (pq.top().second <= (i - k))
            {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends