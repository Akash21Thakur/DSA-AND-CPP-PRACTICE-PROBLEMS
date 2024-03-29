#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[mid], v[low]);
            low++, mid++;
        }
        else if (v[mid] == 1)
            mid++;
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}