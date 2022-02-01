#include <iostream>
#include <climits>
using namespace std;

int maxSumDp(int *a, int n)
{
    int dp[100] = {0};
    dp[0] = a[0] < 0 ? 0 : a[0];
    int maxi = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
            dp[i] = 0;
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

// Space-optimized
int kadaneAlgoDp(int *a, int n)
{
    int curSum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        curSum=max(curSum+a[i],0);
        maxi = max(maxi, curSum);
    }

    return maxi;
}

// Kadane for negative too
int kadane2(int *a, int n)
{
    // int maxi_ans = INT_MIN;
    int max_end_here = 0;
    int max_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_end_here = max_end_here + a[i];
        max_so_far = max(max_end_here, max_so_far);
        max_end_here=max(max_end_here,0);
    }
    // if (max_so_far == 0)
    //     max_so_far = maxi_ans;
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Max Sum = " << maxSumDp(a, n) << endl;
    cout << "Kadane's Algo : " << kadaneAlgoDp(a, n) << endl;
    cout<<"Kadane's for Neg : "<<kadane2(a,n)<<endl;
}