#include<iostream>
#include<vector>
using namespace std;

//pivot --> largest element in the sorted rotated array
//time: logn ... space : constant

int findPivot(vector<int> &v,int n)
{
    if(n==0)   return -1;
    if(n==1)   return v[0];
    int start=0,end=n-1;

    //first find the smallest or the start of the array
    while(start<end)
    {
        int mid=(start+end)/2;
        if(v[mid]>v[n-1])  start=mid+1;  
        else  end=mid;
    }

    
    int ans=-1;

    //if the starting element is the amallest then largest is the last one...or say the array is not rotated 
    if(v[0]==v[start])  ans=v[n-1];
    //maximum is just before the the smallest one
    else  ans=v[start-1];

    return ans;

}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    cout<<"Pivot Element : "<<findPivot(v,n)<<endl;
}