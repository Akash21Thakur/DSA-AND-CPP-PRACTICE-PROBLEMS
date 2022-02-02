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

    // METH-1 -->O(nlogn)
    //   using the sort stl

    // METH-2 --> O(n+n)
    // count number of 0-1-2 than place it into the array

    // METH-3 -->O(n)
    //  DNF(Dutch-National-Flag) Sort -> O(n)
    //
    //  1. low=mid=0,high=n-1
    //     while(mid<=high)
    //  2. 0 -> swap(l,m);   low++;mid++;
    //  3. 1-> mid++;
    //  4. 2-> swap(m,h); high--;

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    for (auto num : nums)
        cout << num << " ";
}