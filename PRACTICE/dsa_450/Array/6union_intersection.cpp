#include <iostream>
#include <set>
#include <vector>
using namespace std;

// coz set ds keeps only the unnique element
int findUnion(vector<int> &a, vector<int> &b, int n, int m)
{
    set<int> mp;

    for (int i = 0; i < n; i++)
        mp.insert(a[i]);

    for (int i = 0; i < m; i++)
        mp.insert(b[i]);

    return mp.size();
}

int findIntersection(vector<int> &a, vector<int> &b, int n, int m)
{
    set<int> mp;

    for (int i = 0; i < n; i++)
        mp.insert(a[i]);
    int count = 0;

    // check if b element are already present in set,
    //   if so count++ and delete the element from the set

    for (int i = 0; i < m; i++)
    {
        if (mp.find(b[i]) != mp.end())
            count++;
    }

    return count;
}

int main()
{
    int n;
    cout << "Size arr1: " << endl;
    cin >> n;
    vector<int> nums;
    cout << "Enter Elements arr1: " << endl;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    int n2;
    cout << "Size arr2: " << endl;
    cin >> n2;
    vector<int> nums2;
    cout << "Enter Elements arr2: " << endl;

    for (int i = 0; i < n2; i++)
    {
        cin >> temp;
        nums2.push_back(temp);
    }

    cout << "\nCount of Union : " << findUnion(nums, nums2, nums.size(), nums2.size());
    cout << "\nCount of Union : " << findIntersection(nums, nums2, nums.size(), nums2.size());
}
