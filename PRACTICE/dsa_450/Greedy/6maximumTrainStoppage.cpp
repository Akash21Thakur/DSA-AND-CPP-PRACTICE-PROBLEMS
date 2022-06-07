#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prob: given train's : arrival, departure, platform
// we need find maximum number that can stop in the station

// approach:
// sort on the basis of departure time...and check for each platform independently
// if next train's arrival overlap with previous departure...leave the train else count++

// ds:
// n-vector of pair---> n_row gives platform
// pair<departure,arrival>   easy for sorting so departure is first

int countStoppage(int ar[][3], int n, int m)
{
    // row gives platforms
    vector<pair<int, int>> v[n + 1];

    // insert in the ith entry's platform number vector
    // with pair of <depart,arrival>
    for (int i = 0; i < m; i++)
    {
        v[ar[i][2]].push_back({ar[i][1], ar[i][0]});
    }

    // sort all the vector
    for (int i = 0; i <= n; i++)
        sort(v[i].begin(), v[i].end());

    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (v[i].size() == 0)
            continue;

        // first train for all platform will also be selected
        count++;
        int x = 0; // track for selected train index from ith platform
        for (int j = 1; j < v[i].size(); j++)
        {
            // last selected train's depart time must be less or equal to current train arrival time
            if (v[i][j].second >= v[i][x].first)
            {
                x = j;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[6][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << countStoppage(arr, 2, 5);
    return 0;
}