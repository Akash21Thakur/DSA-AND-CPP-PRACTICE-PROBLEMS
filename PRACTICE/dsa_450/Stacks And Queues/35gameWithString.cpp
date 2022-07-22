//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                pq.push(freq[i]);
        }

        // remove k char... from top freq char.
        while (k--)
        {
            int temp = pq.top() - 1;
            pq.pop();
            if (temp > 0)
                pq.push(temp);
        }

        int ans = 0;
        // calc. answer
        while (!pq.empty())
        {
            ans += (pq.top() * pq.top());
            pq.pop();
        }
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
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends