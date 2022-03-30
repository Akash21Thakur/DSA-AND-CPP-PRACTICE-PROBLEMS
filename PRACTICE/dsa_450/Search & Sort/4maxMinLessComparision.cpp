#include<iostream>
#include<vector>

using namespace std;

pair<int,int> findMinMax(vector<int> &v)
{
    int mini,maxi,i;
    int n=v.size();

    if(n%2==0)//even entries
    {
        if(v[0]>v[1])
        {
            maxi=v[0];
            mini=v[1];
        }
        else{
            maxi=v[1];
            mini=v[0];
        }
        i=2;
    }
    else{
        mini=maxi=v[0];
        i=1;
    }

    while(i<n-1)
    {
        if(v[i]<v[i+1])
        {
            mini=min(v[i],mini);
            maxi=max(v[i+1],maxi);
        }
        else
        {
            mini=min(v[i+1],mini);
            maxi=max(v[i],maxi);
        }
        i+=2;
    }

    return {mini,maxi};
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);

    for(int i=0;i<n;i++)
       cin>>v[i];

    pair<int,int> p=findMinMax(v);
    cout<<p.first<<" "<<p.second<<endl;   
}