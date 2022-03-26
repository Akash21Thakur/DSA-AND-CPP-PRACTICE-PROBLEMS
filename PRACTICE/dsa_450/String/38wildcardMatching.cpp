#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;



// https://leetcode.com/problems/wildcard-matching/discuss/1001130/C%2B%2B-Clean-and-concise-bottom-up-dp-code-with-detailed-explanation-easy-to-understand.

//DRAW DP TABLE FOR BETTER UNDERSTANDING.........akash ==> a?*h

class Solution {
public:
    bool isMatch(string s, string p) {
        // vector<vector<bool>> dp(s.size() + 1, vector(p.size() + 1, false));
        int dp[s.size() + 1][p.size() + 1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }
        
        // for(int i=0;i<=s.size();i++)
        // {

        //     for(int j=0;j<=p.size();j++)
        //        cout<<dp[i][j]<<" ";

        //     cout<<endl;   
        // } 
        // cout<<"-----------------------------"<<endl;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        } 

        // for(int i=0;i<=s.size();i++)
        // {

        //     for(int j=0;j<=p.size();j++)
        //        cout<<dp[i][j]<<" ";

        //     cout<<endl;   
        // }

        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution ob;
    string s,p;
    cout<<"String :";
    cin>>s;
    cout<<"Pattern : ";
    cin>>p;

    cout<<"\nANS : "<<ob.isMatch(s,p)<<endl;
    
}