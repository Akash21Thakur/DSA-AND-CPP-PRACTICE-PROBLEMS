#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> x(m), y(n);

        for (int i = 0; i < m - 1; i++)
            cin >> x[i];

        for (int j = 0; j < n - 1; j++)
            cin >> y[j];

        // pick the greater one first to get min. answer as with cutting piecies increases
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int ans = 0;
        int hori = 1, vert = 1; // initial piecies

        while (i < m - 1 and j < n - 1)
        {
            // cutting vertical increases the horizontal piecies
            if (x[i] > y[j])
            {
                ans += (x[i] * hori); // mutiply with the horizontal piecies
                vert++;
                i++;
            }
            // cutting horizontal increases the vertical piecies
            else
            {
                ans += (y[j] * vert); // mutiply with the vertical piecies
                hori++;
                j++;
            }
        }

        while (i < m - 1)
        {
            ans += (x[i] * hori);
            i++;
        }
        while (j < n - 1)
        {
            ans += (y[j] * vert);
            j++;
        }
        cout << ans << endl;
    }
}