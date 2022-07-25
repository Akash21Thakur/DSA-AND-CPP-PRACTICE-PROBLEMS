//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
    string rearrangeString(string s)
    {
        priority_queue<pair<int, char>> pq;
        int count[26] = {0};

        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (count[ch - 'a'])
            {
                pq.push(make_pair(count[ch - 'a'], ch));
            }
        }

        string ans;
        ans.push_back(pq.top().second);

        pair<int, char> block1, block2;
        block1 = pq.top();

        pq.pop();
        // need to switch block1 and block2...to avoid continuous picking
        while (!pq.empty())
        {
            block2 = pq.top();
            pq.pop();
            ans.push_back(block2.second);
            // block1 always holds the prev added char and its freq
            if (block1.first > 1)
                pq.push({block1.first - 1, block1.second});
            swap(block1, block2);
        }

        if (ans.length() != s.length())
            return "-1";

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
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
// } Driver Code Ends