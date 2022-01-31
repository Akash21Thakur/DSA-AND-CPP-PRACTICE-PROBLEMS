#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string ans = "";
    int n = s.length() - 1;

    while (n >= 0)
    {
        string word = "";
        while (s[n] != ' ' and n >= 0)
        {
            word = (s[n]) + word;
            n--;
        }
        if (word.length() != 0)
            ans = ans + word + " ";
        n--;
    }

    return ans.substr(0, ans.length() - 1);
}

int main()
{
    string s = reverseWords("  gfdgh asd   ");
    cout << s << " " << s.length() << endl;
}