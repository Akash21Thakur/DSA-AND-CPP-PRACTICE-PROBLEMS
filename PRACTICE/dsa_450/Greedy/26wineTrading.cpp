#include <iostream>
#include <vector>
#define int long long int
using namespace std;

// take two vector to store buy and sell value...subtract the idx and multiply with the bottles sold

int32_t main()
{
    int n;
    cin >> n;
    while (true)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // buy and sell storing +ve and -ve values resp.
        vector<pair<int, int>> buy;
        vector<pair<int, int>> sell;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                sell.push_back({a[i], i});
            else if (a[i] > 0)
                buy.push_back({a[i], i});
        }

        int ans = 0;
        int i = 0, j = 0; // buy and sell itr.
        while (i < buy.size() and j < sell.size())
        {
            int x = min(buy[i].first, -sell[j].first);
            buy[i].first -= x;
            sell[j].first += x;

            int work = abs(buy[i].second - sell[j].second);

            ans += (x * work);

            if (buy[i].first == 0)
                i++;
            if (sell[j].first == 0)
                j++;
        }

        cout << ans << endl;
        cin >> n;
        if (n == 0)
            break;
    }
}