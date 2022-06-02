// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    // approach
    // greedy: meeting ending earlier are probable to give the max result
    // add to vector and sort on the basis of end time
    // now count++ if limit<next meeting start time

    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back({start[i], end[i]});
        }

        sort(ans.begin(), ans.end(), compare);

        int count = 1, limit = ans[0].second;

        for (int i = 1; i < n; i++)
        {
            if (ans[i].first > limit)
            {
                limit = ans[i].second;
                count++;
            }
        }
        return count;
    }
};

// {  Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends