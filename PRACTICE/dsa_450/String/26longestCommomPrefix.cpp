#include<iostream>
#include<vector>
using namespace std;


//Try yourself problem ...easy hi h ban jayega
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans=strs[0]; //in the begining
        int idx=ans.length(),temp,j;
        for(int i=1;i<strs.size();i++)
        {
            temp=0,j=0;
            while(temp<idx and j<strs[i].length() and strs[i][j]==ans[temp])
            {
                temp++;
                j++;
            }
            idx=min(idx,temp);
            
            
        }
        return ans.substr(0,idx);
    }
};