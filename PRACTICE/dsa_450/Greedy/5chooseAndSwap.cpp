// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// own_code and logic
class Solution
{
public:
    string chooseandswap(string a)
    {
        int n = a.length();
        // stores the first occ. of all the character
        vector<int> v(27, -1);
        for (int i = 0; i < n; i++)
        {
            if (v[a[i] - 'a'] == -1)
                v[a[i] - 'a'] = i;
        }

        // finding if the ch has any character beyond it lexo_small in string
        char ch2 = '$', ch1;
        for (int i = 0; i < n; i++)
        {
            int m = a[i] - 'a'; // to check if prev alphabets appers
            for (int j = 0; j < m; j++)
            {
                if (v[j] != -1 and v[j] > i)
                {
                    ch1 = a[v[j]];
                    ch2 = a[i];
                    break;
                }
            }
            if (ch2 != '$')
                break;
        }
        // no such character found
        if (ch2 == '$')
            return a;

        // means character found and we need to swap both
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ch1)
                a[i] = ch2;
            else if (a[i] == ch2)
                a[i] = ch1;
        }
        return a;
    }
};

// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}
// } Driver Code Ends