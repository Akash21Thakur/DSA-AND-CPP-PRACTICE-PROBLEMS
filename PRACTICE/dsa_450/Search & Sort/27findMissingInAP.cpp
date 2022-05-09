#include<iostream>
#include<vector>

using namespace std;

int helperRecurr(vector<int> &v,int low,int high,int diff)
{
    int mid=(low+high)/2;

    if(v[mid+1]-v[mid]!=diff)
       return v[mid]+diff;
    if(mid>0 and v[mid-1]-v[mid]!=diff)
       return v[mid]-diff;
    if(v[mid]!=v[0]+ (diff*mid))
       return helperRecurr(v,low,mid-1,diff);
    
       return helperRecurr(v,mid+1,high,diff);         
}

int findMissing(vector<int> &v,int n)
{
    int diff=(v[n-1]-v[0])/n;

    return helperRecurr(v,0,n-1,diff);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Missing number is : "<<findMissing(v,n)<<endl;    
}