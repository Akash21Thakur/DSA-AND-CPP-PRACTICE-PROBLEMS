#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxMeeting(int *s, int *f, int n)
{
    // sort on the basis of finish time
    //  check if current starting time is greater than prev selected finish time
    //  if so updated the answer and the time_limit

    pair<int, int> p[n + 1];

    for (int i = 0; i < n; i++)
    {
        p[i].first = f[i]; // finish time
        p[i].second = i;   // index
    }

    sort(p, p + n);

    // first meeting is always selected (sorted)
    vector<int> v;
    v.push_back(p[0].second + 1);
    int time_limit = p[0].first;

    // checking for the remaining meetings
    for (int i = 1; i < n; i++)
    {
        if (s[p[i].second] > time_limit)
        {
            v.push_back(p[i].second + 1);
            time_limit = p[i].first;
        }
    }
    return v;
}

int main()
{
    int s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    int f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};

    vector<int> ans = maxMeeting(s, f, 8);
    for (auto x : ans)
        cout << x << " ";
}