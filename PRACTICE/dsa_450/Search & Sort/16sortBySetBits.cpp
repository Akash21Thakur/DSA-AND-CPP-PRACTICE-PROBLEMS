// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


    
    int cntBits(int num)
    {
        int bits=0;
        while(num)
        {
            if(num&1)
               bits++;
            num=num>>1;   
        }
        return bits;
    }
    
    bool custComp(int a,int b)
    {
        int count1=cntBits(a);
        int count2=cntBits(b);
        
        if(count1<=count2)
          return false;
        return true;  
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        sort(arr,arr+n,custComp);
    }


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // Solution ob;
        sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends