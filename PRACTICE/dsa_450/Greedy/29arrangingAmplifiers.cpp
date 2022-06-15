#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Prob: find max. answer of amplification if formula(X^Y)
//  values do not repeat except 1
// Algo: sort in descending order will give max. ans;
//   NOTE: 2&3 will be exception and 1 should be printed before the order starts

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
                one++;
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < one; i++)
            cout << 1 << " ";

        // incase the array has only 2 and 3 apart from 1
        if ((n - one == 2) and v[0] == 3 and v[1] == 2)
            cout << "2 3";
        else
        {
            for (int i = 0; i < n - one; i++)
                cout << v[i] << " ";
        }
        cout << endl;
    }
}