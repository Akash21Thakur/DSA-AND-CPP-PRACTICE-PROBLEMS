#include<iostream>
#include<vector>
using namespace std;

// for reference : Striver 

class Solution {
    
    int helper(int i,int j,string s,string t,vector<vector<int>> &dp)
    {
        if(i==s.length())   return t.length()-j;  //insert the remaining in s
        if(j==t.length())   return s.length()-i;  //remove the extra element from s
        
        if(dp[i][j]!=-1)    return dp[i][j]; //if already calculated
        
        if(s[i]==t[j])      return dp[i][j]=helper(i+1,j+1,s,t,dp);  //if match found...move to next char(s&t)
        
        int insert=1+helper(i,j+1,s,t,dp);   //insertion of new
        int remove=1+helper(i+1,j,s,t,dp);   //remove the xtra
        int replace=1+helper(i+1,j+1,s,t,dp);  // replace 
        
        return dp[i][j]=min(insert,min(remove,replace));  //memoization and returning the minimum one
    }
    
    
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));  //dp 2d array ...
         return helper(0,0,word1,word2,dp);
    }
};