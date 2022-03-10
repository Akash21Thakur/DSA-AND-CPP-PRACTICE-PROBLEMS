#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helperFn(string s,int left,int right,vector<string> &ans)
    {
        if(left==right){
          ans.push_back(s);return;}
        
        for(int i=left;i<=right;i++)
        {
            swap(s[left],s[i]);
            helperFn(s,left+1,right,ans);
            swap(s[left],s[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        
        helperFn(S,0,S.length()-1,ans);
        sort(ans.begin(),ans.end()); //just to match the answer order...not eccessary as such
        return ans;
    }

    int main()
    {
        string s;
        cout<<"Enter string : ";
        cin>>s;
        vector<string> v=permutation(s);

        for(string s: v)
           cout<<s<<" ";
    }