#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;

        vector<int> x_cord;
        vector<int> y_cord;
        // we would store 0 and x...in x_cord for boundaries ...same for y_cord
        x_cord.push_back(0);
        x_cord.push_back(x + 1);
        y_cord.push_back(0);
        y_cord.push_back(y + 1);

        for (int i = 2; i < n + 2; i++)
        {
            int t1, t2;
            cin >> t1;
            cin >> t2;
            x_cord.push_back(t1);
            y_cord.push_back(t2);
        }

        sort(x_cord.begin(), x_cord.end());
        sort(y_cord.begin(), y_cord.end());

        int mx = 0, my = 0;
        // finding the max gap. in both the axis
        for (int i = 0; i < n + 1; i++)
        {
            mx = max(mx, x_cord[i + 1] - x_cord[i] - 1);
            my = max(my, y_cord[i + 1] - y_cord[i] - 1);
        }

        cout << mx * my << endl;
    }
}
