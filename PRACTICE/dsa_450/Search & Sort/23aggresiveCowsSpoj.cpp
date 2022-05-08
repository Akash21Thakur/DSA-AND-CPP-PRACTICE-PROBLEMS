#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//SIMILAR TO SPOJ AGGRESSIVE COW PROBLEM
//leetcode problem
class Solution {
public:
    bool checkValidity(vector<int> &s,int n,int c,int diff)
{
    int count=1,currPos=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]-s[currPos]>=diff)
        {
            currPos=i;
            count++;
        }
        if(count==c)   return true;
    }
    return false;
}
    int maxDistance(vector<int>& stalls, int c) {
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());

        int low=1,high=stalls[n-1]-stalls[0];
        // int ans=-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(checkValidity(stalls,n,c,mid))
            {
                // ans=stalls[mid];
                low=mid+1;
            }
            else
              high=mid-1;
        }
        
       return high;

    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int> stalls(n);
        for(int i=0;i<n;i++)
          cin>>stalls[i];
        // 1. sort  
        // 2. find low_high
        // 3. binary search finding the largest min difference
        // 4. check fn for difference validity
       Solution ob;

       cout<<ob.maxDistance(stalls,c);


    }
}