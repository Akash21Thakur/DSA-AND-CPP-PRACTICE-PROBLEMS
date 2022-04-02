#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout<<"CASE #"<<i<<":\n";
        int col1[3], col2[3], col3[3], col4[3];
        // printer--1
        cin >> col1[0] >> col2[0] >> col3[0] >> col4[0];
        // printer--2
        cin >> col1[1] >> col2[1] >> col3[1] >> col4[1];
        // printer--
        cin >> col1[2] >> col2[2] >> col3[2] >> col4[2];

        int ans[4];
        ans[0] = *min_element(col1, col1 + 3);
        ans[1] = *min_element(col2, col2 + 3);
        ans[2] = *min_element(col3, col3 + 3);
        ans[3] = *min_element(col4, col4 + 3);

        // check sum
        int sum = ans[0] + ans[1] + ans[2] + ans[3];

        if (sum < 1000000)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            int to_get = 1000000;
            // colors unit
            for (int i = 0; i < 4; i++)
            {
                int temp;
                if (to_get >= ans[i])
                {
                    cout<<ans[i]<<" ";
                    // temp = to_get - ans[i];
                    to_get -= ans[i];
                }
                else
                {
                    cout<<to_get<<" ";
                    to_get = 0;
                }
                // cout << temp << " ";
            }
            cout << endl;
        }
    }
}