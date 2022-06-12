// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << maxSum(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends

long long int maxSum(int arr[], int n)
{
    // Time:O(nlogn), Space: O(n)
    //  int n = v.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = arr[i];

    sort(v.begin(), v.end());

    vector<int> temp;
    // insert alternately small and big
    for (int i = 0; i < n / 2; i++)
    {
        temp.push_back(v[i]);
        temp.push_back(v[n - i - 1]);
    }

    // when n is odd
    if (n & 1)
        temp.push_back(v[n / 2]);

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += abs(temp[i] - temp[i + 1]);

    // diff of first and last
    ans += abs(temp[0] - temp[n - 1]);

    return ans;

    // space: O(1)
    // sort(arr,arr+n);
    // int sum=0;
    // carefully observe the pattern...that start-n/2 element are 2X substracted...while end half are 2X added
    // for(int i=0;i<n/2;i++)
    // {
    //     sum-=2*arr[i];
    //     sum+=2*arr[n-i-1];
    // }

    // return sum;
}