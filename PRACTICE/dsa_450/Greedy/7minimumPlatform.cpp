// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // method-1 pq.  time: nlogn , space: O(n)
        // sort arr. with corres. dep. and traverse the arrival keeping
        // track of pq. and updating pq. accordingly

        // 	vector<pair<int,int>> v;
        // 	for(int i=0;i<n;i++)
        // 	   v.push_back({arr[i],dep[i]});
        // 	sort(v.begin(),v.end());

        // 	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // minheap
        // 	int count=1,maxi=1;

        // 	for(int i=0;i<n;i++)
        // 	{
        // 	    if(pq.empty())
        // 	    {
        // 	        pq.push({v[i].second,v[i].first});
        // 	    }
        // 	    else if(v[i].first>pq.top().first)
        // 	    {
        // 	        pq.pop();
        // 	        pq.push({v[i].second,v[i].first});
        // 	    }
        // 	    else
        // 	    {
        // 	        pq.push({v[i].second,v[i].first});
        // 	    }
        // 	}

        // 	return pq.size();
        // method-2   time: nlogn  spase: O(1)
        // sort arr and depart. separately
        // here we are mainly concerned about the empty platform...
        // so if the next train comes before or on the current train's platform timing...w'll need a new platform
        // we use two pointer for the same

        sort(arr, arr + n);
        sort(dep, dep + n);

        int maxi = 1, count = 1;
        int i = 1, j = 0;

        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                count++;
                maxi = max(maxi, count);
                i++;
            }
            else
            {
                count--;
                j++;
            }
        }

        return maxi;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
} // } Driver Code Ends