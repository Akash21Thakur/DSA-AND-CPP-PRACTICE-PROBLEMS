#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool check(vector<int> &v, int p, int mid)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int time = v[i];
        int j = 2;

        while (time <= mid)
        {
            count++;
            time += (v[i] * j);
            j++;
        }
        if (count >= p)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int n;
        cin >> n;
        vector<int> v(n);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            maxi = max(maxi, v[i]);
        }

        int low = 0;
        int high = maxi * ((p * (p + 1)) / 2);
        int res = 0;
        // binary_search
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (check(v, p, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        cout << res << endl;
    }
}