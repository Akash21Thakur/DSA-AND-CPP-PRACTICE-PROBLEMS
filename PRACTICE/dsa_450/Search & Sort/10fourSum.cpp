// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        if(arr.size()==0) return ans;
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        //first element
        for(int i=0;i<n;i++)
        {
            //second element
            for(int j=i+1;j<n;j++)
            {
                int remain=k-(arr[i]+arr[j]);
                int left=j+1;
                int right=n-1;
                
                //two pointer approach ...like always
                while(left<right)
                {
                    int sum=(arr[left]+arr[right]);
                    
                    if(sum<remain)   left++;
                    else if(sum>remain)  right--;
                    else {
                        vector<int> v(4,0);
                        v={arr[i],arr[j],arr[left],arr[right]};
                        ans.push_back(v);
                        
                        //remove 3rd duplicate
                        while(left<right and arr[left]==v[2]  )  {left++;}
                        
                        //remove 4th duplicate
                        while(left<right and arr[right]==v[3] )  {right--;}
                    }
                }
                
                //remove 2nd duplicate
                while(arr[j+1]==arr[j] and j+1<n)   {j++;}
            }
            
            //remove 1st duplicate
            while(arr[i+1]==arr[i] and i+1<n)   {i++;}
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends