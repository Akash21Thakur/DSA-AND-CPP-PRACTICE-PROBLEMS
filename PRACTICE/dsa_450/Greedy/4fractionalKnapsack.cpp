// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

static bool compare(Item a, Item b)
{
    double val1 = ((a.value * 1.0) / (a.weight));
    double val2 = ((b.value * 1.0) / (b.weight));
    return val1 > val2;
}

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sort on the basis of fraction of value/weight
        sort(arr, arr + n, compare);
        double ans = 0.0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((sum + arr[i].weight) <= W)
            {
                sum += arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                // for the last if remaining arr element
                // will fill if sum!=W
                // by the value of temp*(val/weight)
                int temp = (W - sum);
                ans = ans + temp * ((arr[i].value * 1.0) / arr[i].weight);
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends