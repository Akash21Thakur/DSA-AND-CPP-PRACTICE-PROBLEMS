#include<iostream>
#include<vector>

using namespace std;
#define ll long long int

ll crossInversion(ll *v,int s,int mid,int e)
{
    ll i=s,j=mid+1,k=s;
    vector<ll> temp(500000);
    ll count=0;
    while(i<=mid and j<=e)
    {
        if(v[i]<=v[j])
          temp[k++]=v[i++];
        else{
            count+=mid-i+1;
            temp[k++]=v[j++];
            // j++;

        }  
    }

    while(i<=mid)
       temp[k++]=v[i++];

    while(j<=e)
       temp[k++]=v[j++];

    //merge into the original array
    for(k=s;k<=e;k++)
      v[k]=temp[k];

    return count;        
}


ll helpermergesort(ll *v,int s,int e)
{
    if(s>=e)  return 0;

    ll mid=(s+e)/2;

    ll x=helpermergesort(v,s,mid);
    ll y=helpermergesort(v,mid+1,e);

    ll z=crossInversion(v,s,mid,e);

    return x+y+z;



}
long long int inversionCount(ll *v, long long N)
    {
        return helpermergesort(v,0,N-1);
    }
int main()
{
    ll n;
    cin>>n;
    ll v[n];
    for(int i=0;i<n;i++)
       cin>>v[i];

    cout<<"Number of Inversion Count : "<<inversionCount(v,n)<<endl;   

}