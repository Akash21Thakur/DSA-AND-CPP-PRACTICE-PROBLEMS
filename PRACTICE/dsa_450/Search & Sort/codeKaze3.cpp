#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        int n;
        cin>>n;
        vector<int> v(n,0);

        for(int i=0;i<n;i++)
          cin>>v[i];

        sort(v.begin(),v.end());  
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(v[i]>=count)
            {
                count++;
                // ans++;
            }  
            

        }
        cout<<count<<endl;
    }
}