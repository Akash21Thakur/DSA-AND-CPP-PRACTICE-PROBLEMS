// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans(2, 0);

        // sorting is req. to for greedily purchase
        sort(candies, candies + N);

        // finding mini
        int i = 0, j = N - 1;
        while (i <= j)
        {
            ans[0] += candies[i];
            i++;
            j -= K;
        }

        // finding maxi
        i = 0, j = N - 1;
        while (i <= j)
        {
            ans[1] += candies[j];
            j--;
            i += K;
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends