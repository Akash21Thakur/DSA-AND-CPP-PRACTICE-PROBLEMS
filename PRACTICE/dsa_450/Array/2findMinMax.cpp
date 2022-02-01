#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> findMinMax(vector<int> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // everytime compare and update if needed
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
            maxi = nums[i];
        if (nums[i] < mini)
            mini = nums[i];
    }
    return {mini, maxi};
}

int main()
{
    vector<int> nums;
    cout << "Size : ";
    int n;
    cin >> n;
    cout << "Enter elements : ";
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        nums.push_back(t);
    }

    // pair<int, int> ans = findMinMax(nums);
    // cout << "Minimum : " << ans.first << endl;
    // cout << "Maximum : " << ans.second << endl;

    // INBUILT FUNCTION
    int mini = *min_element(nums.begin(), nums.end());
    int maxi = *max_element(nums.begin(), nums.end());

    cout << mini << " " << maxi << endl;
}