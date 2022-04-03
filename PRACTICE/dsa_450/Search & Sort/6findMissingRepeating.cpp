// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int ans[2];
 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        //method-1
        //use has map to find the frequency of all...0-->missing,,,2-->repeated
        
        //method-2  -->avoids extra space
        //traverse and negate the arr[arr[idx]]
        // --->which is already -ve--means repeated one found
        // ---> traverse once more the element which is still +ve...resp. index is the missing one
        
        
        // for(int i=0;i<n;i++)
        // {
        //     if (arr[abs(arr[i]) - 1] > 0)
        //     arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        // else
        //     // if(arr[abs(arr[i])-1]<0)
        //     // {
        //         ans[0]=i+1;
        //     // }
        //     // else
        //     //   arr[abs(arr[i])-1]*=-1;
        // }
        int i;
    // cout << " The repeating element is ";
 
    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            // cout << abs(arr[i]) << "\n";
            ans[0]=abs(arr[i]);
    }
 
    // cout << "and the missing element is ";
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            ans[1]=(i + 1);
    }
        //finding the missing one
        // for(int i=0;i<n;i++)
        // {
        //     if(arr[abs(arr[i])-1]>0)
        //       ans[1]=i+1;
        //     arr[abs(arr[i])-1]*=-1;  
        // }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends