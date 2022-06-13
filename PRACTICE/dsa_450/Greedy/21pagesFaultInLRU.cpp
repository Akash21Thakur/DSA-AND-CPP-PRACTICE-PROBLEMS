// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        // find the paging fault: when the page is not found int the cache
        // algo:
        //   search if page present
        // if not found:
        // count++;
        // remove the starting(when size==  cache capacity)...and add page to end
        // else:
        // remove starting one and add it the end as it is noew the most recently used

        // --> one can use hashmap also...makes searching O(1) and Doubly linked list to make adding and removing O(1)
        int count = 0;
        vector<int> v;
        int i;
        for (i = 0; i < N; i++)
        {
            auto it = find(v.begin(), v.end(), pages[i]);

            if (it == v.end())
            {
                // when size if size equals capacity
                // remove the first element
                if (v.size() == C)
                {
                    v.erase(v.begin());
                }
                v.push_back(pages[i]);
                count++;
            }
            else
            {
                // make it most recently used...and remove the former one
                v.erase(it);
                v.push_back(pages[i]);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, C;
        cin >> N;
        int pages[N];
        for (int i = 0; i < N; i++)
            cin >> pages[i];
        cin >> C;

        Solution ob;
        cout << ob.pageFaults(N, C, pages) << "\n";
    }
    return 0;
} // } Driver Code Ends