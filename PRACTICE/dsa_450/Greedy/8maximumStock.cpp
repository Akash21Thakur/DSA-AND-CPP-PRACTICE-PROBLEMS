// { Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        // greedily: sort on the basis of less price mapped to day
        // stock bought till k is sufficient to make one

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {price[i], i + 1};
        }

        // sort
        sort(v.begin(), v.end());

        int stock = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = v[i].first * v[i].second;

            if (k >= temp)
            {
                stock += v[i].second;
                k -= temp;
            }
            else
            {
                // returns the floor value for the possible purchase if can't purchase all
                stock += (k / v[i].first);
                break;
            }
        }

        return stock;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        Solution ob;
        int ans = ob.buyMaximumProducts(n, k, price);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends