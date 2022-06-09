// { Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool compare(int a, int b)
{
    return a > b;
}

class Solution
{
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {
        // as number of piecies increases with cuts , so we need to cut with max cost...then min ones
        // also with every vertical cut...hori. multiple piecies increses and vice versa
        // sort both in decresing order and perform the operation

        sort(X.begin(), X.end(), compare);
        sort(Y.begin(), Y.end(), compare);

        // at first
        int cost = 0, hori = 1, vert = 1; // piecies before are 1 each

        int i = 0, j = 0;

        while (i < M and j < N)
        {
            if (X[i] > Y[j])
            {
                cost += (X[i] * vert);
                hori++;
                i++;
            }
            else
            {
                cost += (Y[j] * hori);
                vert++;
                j++;
            }
        }

        // if remaining vertical to be cut
        while (i < M)
        {
            cost += (X[i] * vert);
            i++;
        }
        // horizontal ramaining
        while (j < N)
        {
            cost += (Y[j] * hori);
            j++;
        }

        return cost;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> X(m - 1), Y(n - 1);
        for (int i = 0; i < m - 1; i++)
        {
            cin >> X[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> Y[i];
        }
        Solution ob;
        int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
// } Driver Code Ends