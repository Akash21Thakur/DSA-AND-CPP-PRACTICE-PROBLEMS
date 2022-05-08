#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define ll long long int
using namespace std;

//long long int should be taken into consideration
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // 1.sort
        // 2.merge
        // 3.search

        int n,q;
        cin>>n>>q;
        vector<pair<ll,ll>> v;
        ll a,b;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            v.push_back({a,b});
        }
        // 1.
        sort(v.begin(),v.end());

        // 2.
        int idx=0;
        for(int i=1;i<n;i++)
        {
            if(v[idx].second>=v[i].first)
            {
                v[idx].second=max(v[idx].second,v[i].second);
            }
            else
            {
                idx++;
                v[idx]=v[i];
            }
        }

        // 3.
        
        while(q--)
        {
			ll k;
            cin>>k;
            ll range,ans=-1;

            for(int i=0;i<=idx;i++)
            {
                range=v[i].second-v[i].first+1;
                if(k<=range)
                {
                    ans=v[i].first +k-1;
                    break;
                }
                else
                k-=range;

            }
            cout<<ans<<endl;

        }

    }
}
