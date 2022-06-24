// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // striver
        // push all the number from 1-n ..and calc. the factorial(n-1)
        vector<int> v;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            v.push_back(i);
            fact = fact * i;
        }

        v.push_back(n); // last number
        string ans = "";
        k = k - 1; // coz 0-based indexing

        while (true)
        {
            ans = ans + to_string(v[k / fact]); // starting of the permutation which will be fixed
            v.erase(v.begin() + (k / fact));
            if (v.size() == 0)
                break;
            k = k % fact;           // k/fact found earlier...remaining is k%fact
            fact = fact / v.size(); // coz number of factorial decreases by 1
        }
        return ans;
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
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends