#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Size : " << endl;
    cin >> n;
    vector<int> nums;
    cout << "Enter Elements : " << endl;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    int k;
    cout << "Enter k : ";
    cin >> k;
    // METHOD-1
    //  sort and return the k-1 element
    //  O(nlogn)

    // sort(nums.begin(), nums.end());
    // cout << nums[k - 1] << endl;

    // METHOD-2
    // use min_heap...
    // insert all the element then pop k-1 element
    // O(n+klogn)  ~ LINEAR

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(nums[i]);

    for (int i = 0; i < k - 1; i++)
        minHeap.pop();

    cout << minHeap.top() << endl;
}