// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i=0,j=1;
    while(i<size and j<size)
    {
        if(i!=j and abs(arr[j]-arr[i])==n)
           return true;
        else if(arr[j]-arr[i]<n)//diff needs to be increased
           j++;
        else//diff need to be decreased
           i++;
    }
    return false;
    
}