#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isGreater(vector<int> &v,int n,int m,int height)
{
    long long int sum=0;  //important to take long
    for(int i=0;i<n;i++)
    {
        if(v[i]>height)
          sum+=v[i]-height;
          
    }
    if(sum>=m)
           return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int maxi = INT_MIN;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }

    // binary_search_approach
    int low = 0, high = maxi;
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(isGreater(v,n,m,mid))
        {
            res=mid;
            low=mid+1;
        }
        else
          high=mid-1;

    }
    cout<<res;
    return 0;
}