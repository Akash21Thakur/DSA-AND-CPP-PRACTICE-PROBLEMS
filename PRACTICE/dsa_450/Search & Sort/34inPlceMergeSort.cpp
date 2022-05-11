#include<iostream>
#include<vector>

using namespace std;


/*
// METHOD-1---> N^2LOGN
// reverse whenever conflict found...right one is less than left element

void mergeSort(vector<int> &v,int s1,int mid,int e)
{
    int s2=mid+1;
    if(v[mid]<=v[s2])
        return;

    while(s1<=mid and s2<=e)
    {
        if(v[s1]<=v[s2])
           s1++;
        else
        {
            int idx=s2;
            int temp=v[s2];

            while(idx!=s1)
            {
                v[idx]=v[idx-1];
                idx--;
            }
            v[idx]=temp;
            s2++;
            s1++;
            mid++;
        }   
    }    
}

void merge(vector<int> &v,int s,int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        merge(v,s,mid);
        merge(v,mid+1,e);

        mergeSort(v,s,mid,e);
    }
   
}
*/


int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
       cin>>v[i];

    merge(v,0,n-1);   
    for(int i=0;i<n;i++)
       cout<<v[i]<<" ";
}