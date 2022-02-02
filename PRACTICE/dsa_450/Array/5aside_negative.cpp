#include <iostream>
#include <vector>
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

    // quick_sort with condition  -->O(n)
    int j = 0;
    for (int i = 0; i < n; i++)

        if (nums[i] < 0)
            swap(nums[i], nums[j++]);

    for (auto num : nums)
        cout << num << " ";
}