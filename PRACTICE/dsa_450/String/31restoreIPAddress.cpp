#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/restore-ip-addresses/


class Solution {
    
    
public:
   //discuss and neet code
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;
        helper(s,0,0,temp,result);  //string,start,step size(max 3),temp is the intermediate string
        return result;
    }
    
    void helper(string s,int start,int step,string temp,vector<string> &result)
    {
        if(s.size()==start and step==4)
        {
            temp.erase(temp.end()-1);//removes the last dot
            result.push_back(temp);
            return;
        }
        
        if(s.size()-start>(4-step)*3)   return;  //if the remaining digits are more than required...simply return w/o calculating further
        if(s.size()-start<(4-step))     return;  //if remaining digits are less than the reuired steps max is 3
        
        int num=0;
        
        for(int i=start;i<start+3;i++)
        {
            num=num*10+(s[i]-'0');
            if(num<=255){
                temp+=s[i];
                
                helper(s,i+1,step+1,temp+'.',result);
            }
            if(num==0) break;
        }
    }
};