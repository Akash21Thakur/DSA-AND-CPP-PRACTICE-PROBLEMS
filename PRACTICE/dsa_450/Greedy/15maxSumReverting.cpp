// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        long long int sum = 0;

        // revert only neg values
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0 and k)
            {
                a[i] = -a[i];
                k--;
            }
        }

        // take sum
        for (int i = 0; i < n; i++)
            sum += a[i];

        // if k is even will not affect the numbers value at end...
        // if k is remaining and is odd...we need to remove it form the sum X2
        if (k & 1)
        {
            int mini = *min_element(a, a + n);
            sum -= 2 * mini;
        }

        return sum;
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
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
} // } Driver Code Ends