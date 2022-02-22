#include <iostream>
#include <climits>
using namespace std;

// Time  : min(logn,logm)
double calMedian(int *a, int *b, int n, int m)
{
    if (n > m)
        calMedian(b, a, m, n);

    int start = 0, end = n;
    int realmed = (m + n + 1) / 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int leftsize = mid;
        int rightsize = realmed - mid;

        int leftA = (leftsize > 0) ? a[leftsize - 1] : INT_MIN;
        int leftB = (rightsize > 0) ? b[rightsize - 1] : INT_MIN;

        int rightA = (leftsize > 0) ? a[leftsize] : INT_MAX;
        int rightB = (rightsize > 0) ? b[rightsize] : INT_MAX;

        // check if condition matches
        if (leftA <= rightB and leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2;
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0.0;
}

int main()
{
    int n, m;
    cout << "Enter array-1 size : ";
    cin >> n;
    cout << "Enter array-2 size  : ";
    cin >> m;
    cout << "Enter array-1 elements : ";
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter array-2 Elements : ";

    for (int j = 0; j < m; j++)
        cin >> b[j];

    cout << "Median of array : " << calMedian(a, b, n, m) << endl;
}