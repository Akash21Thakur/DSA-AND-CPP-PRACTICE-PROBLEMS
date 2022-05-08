#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
       cin>>v[i];

    sort(v.begin(),v.end());
    
    vector<int> csum(n,0);
    csum[0]=v[0];
    for(int i=1;i<n;i++)
      csum[i]=csum[i-1]+v[i];

    int round,temp;
    cin>>round;

    vector<vector<int>> ans(round,vector<int> (2));
    for(int i=0;i<round;i++)
    {
        cin>>temp;
        int idx=upper_bound(v.begin(),v.end(),temp)-v.begin()-1;
        cout<<idx<<endl;
        ans[i][0]=idx+1;
        ans[i][1]=csum[idx];
        
    } 

    for(int i=0;i<round;i++)
     cout<<ans[i][0]<<" "<<ans[i][1]<<endl;

}