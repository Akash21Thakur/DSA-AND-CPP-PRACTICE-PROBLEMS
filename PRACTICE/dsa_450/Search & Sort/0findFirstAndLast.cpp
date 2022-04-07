// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n, int x)
{
    int first = -1, last = -1;
    int low = 0, high = n - 1;
    // finding  first
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            if (arr[mid] == x)
                first = mid;
            high = mid - 1; // move to left
        }
        else
            low = mid + 1;
    }

    low = 0, high = n - 1;

    // finding last
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            if (arr[mid] == x)
                last = mid; // move towards right
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return {first, last};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends