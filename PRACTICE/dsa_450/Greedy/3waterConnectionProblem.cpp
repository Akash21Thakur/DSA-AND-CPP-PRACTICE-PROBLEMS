// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // approach:
    // insert the diameter and path mapped to starting node...and mark the end node as false
    // now for every node check if node is starting and is path exist...
    // if so...find the end node of the connected component meanwhile finding the minimum pipe diameter
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<bool> startNode(n + 1, true);
        vector<int> path(n + 1, 0);
        vector<int> diameter(n + 1, 0);

        for (int i = 0; i < p; i++)
        {
            startNode[b[i]] = false; // can't be start as it has incoming pipe
            diameter[a[i]] = d[i];   // diameter is mapped to starting node
            path[a[i]] = b[i];       // possible path for the starting node
        }

        vector<vector<int>> ans;
        // check for all the nodes...if it is a starting node and path exist
        for (int i = 1; i <= n; i++)
        {
            if (startNode[i] and path[i] != 0)
            {
                int start = i;
                int end = path[i];
                int diam = diameter[i];

                while (path[end])
                {
                    diam = min(diam, diameter[end]);
                    end = path[end]; // end is next to next connected node
                }

                ans.push_back({start, end, diam});
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
} // } Driver Code Ends