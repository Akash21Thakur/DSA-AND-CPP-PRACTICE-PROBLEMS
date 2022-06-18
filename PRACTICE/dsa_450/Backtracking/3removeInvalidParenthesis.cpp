#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-invalid-parentheses/discuss/1132245/Bactracking-or-Easy-to-understand-or-C%2B%2B
class Solution
{
public:
    // find number(num) of invalid braces...
    // remove all (num) braces from s and check is remaining is valid...if so check if it has already appeared in the answer...if not add

    vector<string> ans;
    unordered_set<string> mp;

    // counts invalid braces using stack
    int countInvalid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {
                if (st.size() == 0)
                {
                    st.push(')');
                }
                else if (st.top() == ')')
                {
                    st.push(')');
                }
                else if (st.top() == '(')
                {
                    st.pop();
                }
            }
        }

        return st.size();
    }

    void helper(string s, int num)
    {
        // base case
        if (num < 0)
            return;

        if (num == 0)
        {
            if (countInvalid(s) == 0)
                ans.push_back(s); // valid string
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {

            string left = s.substr(0, i);   // left of s[i]
            string right = s.substr(i + 1); // right of s[i]
            string temp = left + right;
            if (mp.find(temp) == mp.end())
            {
                mp.insert(temp);
                helper(temp, num - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        helper(s, countInvalid(s));
        return ans;
    }
};