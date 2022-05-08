#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void insertionSort(vector<int> &a, int m)
{

    for (int i = 0; i < m - 1; i++)
    {
        if (a[i + 1] < a[i])
            swap(a[i + 1], a[i]);
        else
            break;
    }
}
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // method-1 ...will give tle as time: nm
    // int i=0,j=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr1[i]>arr2[0])
    //     {
    //         swap(arr1[i],arr2[0]);
    //         insertionSort(arr2,m);
    //     }
    //     // else i++;
    // }

    // if(n>=k)
    //    return arr1[k-1];
    // k-=n;
    // return arr2[k-1];



    // method-2  time: log(min(n,m)) space : 1
    // ref: Striver

    if (n > m)
        return kthElement(arr2, arr1, m, n, k);

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if(l1<=r2 and l2<=r1)
           return max(l1,l2);
        else if(l1>r2)
           high=cut1-1;
        else
           low=cut1+1;      
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << "Enter k : ";
    int k;
    cin >> k;

    cout << "Kth Elment : " << kthElement(a, b, n, m, k) << endl;
}