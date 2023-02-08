//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        string ans = "";
        sort(arr, arr + n, greater<int>());
        int carry = 0;
        for (int i = 0; i < n; i += 2)
        {
            int sum = carry + arr[i];
            if (i + 1 < n)
                sum += arr[i + 1];

            ans += to_string(sum % 10);
            carry = sum / 10;
        }

        if (carry)
            ans += "1";

        // remove trailing 0
        while (!ans.empty() and ans.back() == '0')
            ans.pop_back();

        reverse(ans.begin(), ans.end());
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends