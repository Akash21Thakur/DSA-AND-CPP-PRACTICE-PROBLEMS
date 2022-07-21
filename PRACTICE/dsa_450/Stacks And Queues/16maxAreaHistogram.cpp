//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        if (n == 0)
            return 0;
        stack<pair<int, long long>> st;
        st.push({0, arr[0]});
        long long maxi = arr[0];
        pair<int, long long> curr;
        int i = 1;
        for (; i < n; i++)
        {
            if (arr[i] >= st.top().second)
                st.push({i, arr[i]});
            else
            {
                // auto temp=st.top();  st.pop();

                while (!st.empty() and arr[i] < st.top().second)
                {
                    curr = st.top();
                    long long temp = (curr.second) * (i - curr.first);
                    maxi = max(maxi, temp);
                    st.pop();
                }
                st.push({curr.first, arr[i]});
            }
        }
        // auto curr;
        while (!st.empty())
        {
            long long temp = (st.top().second) * (n - st.top().first);
            maxi = max(maxi, temp);
            st.pop();
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends