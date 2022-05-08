// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<pair<int,int>> v(n);
	    
	    for(int i=0;i<n;i++)
	       v[i]={nums[i],i};
	    
	    sort(v.begin(),v.end());
	    
	    //check if match found with the given vector.second matches the index i
	    //if so then it was in the correct place
	    //else swaping is required...and the i must be in the same place to check for the swapped value correct place
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(i!=v[i].second)
	        {
	            ans++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return ans;
	   // return 0;    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends