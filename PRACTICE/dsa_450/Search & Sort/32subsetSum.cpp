#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

//ref : Code library

void subSum(vector<ll> &v,int idx,int n,vector<ll> &s1,ll sum)
{
    if(idx==n)
    {
        s1.push_back(sum);
        return;
    }
    subSum(v,idx+1,n,s1,sum+v[idx]);
    subSum(v,idx+1,n,s1,sum);

}

int main()
{
   ll n,a,b;
   cin>>n>>a>>b;

   vector<ll> v(n);
   for(int i=0;i<n;i++)
      cin>>v[i];

   vector<ll> s1,s2;
   ll sum=0;
   subSum(v,0,n/2,s1,0);
   subSum(v,n/2,n,s2,0);

   sort(s2.begin(),s2.end());
   ll res=0;

   for(int i=0;i<s1.size();i++)
   {
       ll low=lower_bound(s2.begin(),s2.end(),a-s1[i])-s2.begin();
       ll high=upper_bound(s2.begin(),s2.end(),b-s1[i])-s2.begin();

       res+=(high-low);
   }   
  cout<<res<<endl;
}