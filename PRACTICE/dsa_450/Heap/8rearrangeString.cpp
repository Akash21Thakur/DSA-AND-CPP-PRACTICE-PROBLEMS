#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // We one by one take the highest frequency character from the heap and add it to result. After we add, we decrease the frequency of the character and we temporarily move this character out of priority queue so that it is not picked next time.

    string reorganizeString(string s)
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
            return "";

        return ans;
    }
};