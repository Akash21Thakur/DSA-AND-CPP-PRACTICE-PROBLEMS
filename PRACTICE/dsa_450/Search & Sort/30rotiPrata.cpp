#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//ref :  code library


bool check(vector<int> &v,int n,int prata,int mid)
{
    int count=0;
    for(int i=0;i<n;i++)//for each chef
    {
        int time=v[i];  //rank
        int j=2;
        while(time<=mid)
        {
            count+=1;
            time+=(v[i]*j);
            j++;

        }
        if(count>=prata)
           return true;
    }
    return false;  //count remained min. than req. prata
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int prata,n;
        cin>>prata>>n;
        vector<int> v(n);

        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            maxi=max(v[i],maxi);
        }
        int low=0,high=maxi*((prata*(prata+1))/2);
        int ans;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(v,n,prata,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;
        }
        cout<<ans<<endl;
    }
}