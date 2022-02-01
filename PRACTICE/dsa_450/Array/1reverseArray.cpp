#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseAry(vector<int> &nums)
{
    int size = nums.size();

    // swap the first half element(from 1st) with the next half(from last)
    for (int i = 0; i < size / 2; i++)
    {
        swap(nums[i], nums[size - 1 - i]);
    }
}

int main()
{
    vector<int> nums;
    cout << "Size : ";
    int n;
    cin >> n;
    cout << "Enter " << n << " numbers : " << endl;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    reverseAry(nums);

    // STL works for both vector/array and string
    //  reverse(nums.begin(), nums.end());

    for (auto num : nums)
        cout << num << " ";
}