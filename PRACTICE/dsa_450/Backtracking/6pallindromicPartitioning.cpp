#include <iostream>
#include <vector>
using namespace std;

bool isPallin(string s, int low, int high)
{
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// similar to sudoko solver
// add all possible substr and check for rest
// revert while backtracking...(pop_back)

void helperRecurr(vector<vector<string>> &ans, vector<string> &cur, int itr, int n, string s)
{
    // string exhausted
    if (itr >= n)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = itr; i < n; i++)
    {
        if (isPallin(s, itr, i))
        {
            cur.push_back(s.substr(itr, i - itr + 1));

            helperRecurr(ans, cur, i + 1, n, s);

            // backtracking
            cur.pop_back();
        }
    }
}

void allPallinPartition(string s)
{
    vector<vector<string>> ans;

    vector<string> cur_substr;
    int n = s.size();
    helperRecurr(ans, cur_substr, 0, n, s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s;
    cin >> s;

    allPallinPartition(s);
}