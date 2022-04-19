// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // METHOD-1  N*M
    //     void insertionSort(int*b,int m)
    //     {
    //         for(int i=1;i<m;i++)
    //         {
    //             if(b[i]<b[i-1])
    //               swap(b[i],b[i-1]);
    //             else
    //               break;
    //         }
    //     }
    // 	void merge(int a[], int b[], int n, int m) {

    // 	    for(int i=0;i<n;i++)
    // 	    {
    // 	        if(a[i]>b[0])
    // 	        {
    // 	            swap(a[i],b[0]);
    // 	            insertionSort(b,m);

    // 	        }
    // 	    }
    // 	}

    // METHOD-2
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }

    void merge(int *a, int *b, int n, int m)
    {
        int i, j, gap = n + m;

        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            for (i = 0; i + gap < n; i++)
                if (a[i] > a[i + gap])
                    swap(a[i], a[i + gap]);

            for (j = gap > n ? gap - n : 0; i < n and j < m; i++, j++)
                if (a[i] > b[j])
                    swap(a[i], b[j]);

            if (j < m)
            {
                for (j = 0; j + gap < m; j++)
                    if (b[j] > b[j + gap])
                        swap(b[j], b[j + gap]);
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends