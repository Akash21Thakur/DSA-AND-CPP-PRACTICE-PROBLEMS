// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution
{
public:
    int Maximize(int a[], int n)
    {
        sort(a, a + n);
        int prod = 0;
        // a[i]*i...exceeds the int limit so...typecasted to ll
        for (int i = 0; i < n; i++)
        {
            prod = (prod + ((long long int)a[i] * i) % mod) % mod;
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.Maximize(a, n) << endl;
    }
} // } Driver Code Ends