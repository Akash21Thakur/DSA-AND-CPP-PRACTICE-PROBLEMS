#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void helperRecurr(vector<int> &v, int n, bool *cur_element, int no_of_element_selected, bool *soln, int *minDiff, int sum, int cur_sum, int cur_position)
{
    // when goes out of bound
    if (cur_position == n)
        return;

    // if remaining element if less than the req. to for subset of n/2
    if ((n / 2 - no_of_element_selected) > (n - cur_position))
        return;

    // not taking the current element
    helperRecurr(v, n, cur_element, no_of_element_selected, soln, minDiff, sum, cur_sum, cur_position + 1);

    // taking the curr element to first subset
    no_of_element_selected++;
    cur_element[cur_position] = true;
    cur_sum += v[cur_position];

    // if first subset has n/2 element
    if (no_of_element_selected == n / 2)
    {
        // if gives the min diff
        if (abs(sum / 2 - cur_sum) < *minDiff)
        {
            *minDiff = abs(sum / 2 - cur_sum); // update
            // might be the candidate of soln.
            for (int i = 0; i < n; i++)
                soln[i] = cur_element[i];
        }
    }
    else
    {
        helperRecurr(v, n, cur_element, no_of_element_selected, soln, minDiff, sum, cur_sum, cur_position + 1);
    }

    // backtracking
    cur_element[cur_position] = false;
}

void tugOfWar(vector<int> &v, int n)
{
    // tracks if curr. element is included in the first subset
    bool *curr_element = new bool[n];

    // final answer
    bool *soln = new bool[n];

    int min_diff = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        curr_element[i] = soln[i] = false;
    }

    helperRecurr(v, n, curr_element, 0, soln, &min_diff, sum, 0, 0);
    cout << endl
         << "Subset-1: ";
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == true)
            cout << v[i] << " ";
    }
    cout << endl
         << "Subset-2: ";
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == false)
            cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

    tugOfWar(v, 11);
}