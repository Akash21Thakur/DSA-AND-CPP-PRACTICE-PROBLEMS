#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

bool ifSumZero(vector<int> &v)
{
    unordered_set<int> m;
    int pre=0;
    for(int i=0;i<v.size();i++)
    {
        pre+=v[i];
        if(pre==0 or m.find(pre)!=m.end())
          return true;
        m.insert(pre);  


    }
    return false;

}

//longest length of subarray which gives sum=0
int maxSubarSumZero(vector<int> &v,int n)
{
    unordered_map<int,int> m;
    int pre=0,maxi=0;
    for(int i=0;i<n;i++)
    {
        pre+=v[i];
        if(pre==0)  maxi=max(maxi,i+1);     //if cummalative sum=0,length is updated
        if(m.find(pre)!=m.end())       //in case dupilicate found...update length(if necessary)
          maxi=max(maxi,(i-m[pre]));
        else
          m[pre]=i;   //push imto map,new elements
    }
    return maxi;
}

//longest subarray length whose sum=k
int longestSubarrayKsum(vector<int> &v,int n,int k)
{
    unordered_map<int,int> m;
    int pre=0,len=0;
    for(int i=0;i<n;i++)
    {
        pre+=v[i];
        if(pre==k)  len=i+1;
        if(m.find(pre-k)!=m.end())  len=max(len,i-m[pre-k]);
        else  m[pre]=i;
    }
    return len;
}

int main()
{
    vector<int> v;
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    if(ifSumZero(v))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;  

    // cout<<maxSubarSumZero(v,n)<<endl;
    int k;
    cin>>k;
    cout<<longestSubarrayKsum(v,n,k)<<endl;  



}