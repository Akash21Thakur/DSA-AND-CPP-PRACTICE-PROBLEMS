//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // priority_queue<int> maxheap;
    // priority_queue<int,greater<int>,vector<int>> minheap;
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    // Function to insert heap.
    void insertHeap(int &x)
    {
        maxheap.push(x);
        minheap.push(maxheap.top());
        maxheap.pop();

        if (minheap.size() > maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
    }

    // Function to return Median.
    double getMedian()
    {
        if (maxheap.size() > minheap.size())
            return maxheap.top();
        return (minheap.top() + maxheap.top()) / 2.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends