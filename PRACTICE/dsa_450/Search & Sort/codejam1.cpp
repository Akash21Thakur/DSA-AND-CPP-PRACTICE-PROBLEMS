#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cout << "Case  #" << j << " :\n";
        string s;
        cin >> s;
        string ans;
        int flag = 1;

        int n = s.length();
        int i = 0;
        for (; i < n - 1; i++)
        {
            if (s[i] < s[i + 1])
            {
                ans = ans + s[i] + s[i];
                flag = 0;
                break;
            }
            else if (s[i] == s[i + 1])
            {
                ans = ans + s[i] + s[i];
            }
            else
            {
                ans += s[i];
            }
        }
        if (flag)
            cout << s << endl;
        else
        {
            if (i == n - 1)
                cout << (s + s[i]) << endl;
            else
            {
                for (++i; i < n; i++)
                    ans += s[i];
                cout << ans << endl;
            }
        }
    }
}