#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// METHOD-1 -->Time : O(nlogn) , Space : O(1)
//  sort and count all the streak present ...return the maximum length steak

// METHOD-2  --> Time : O(n) , Space : O(n)
//  algo :
//  1. Add all the element to the set
//  2. Check if current_num-1 is present in the set...for all the numbers :
//     --> if so just continue;
//     --> if not check for all its streak above (current_num+1)  and count the streak
//            update accordingly the answer
// Striver's

// Function to return length of longest subsequence of consecutive integers.
int findLongestConseqSubseq(int arr[], int N)
{
    set<int> s;

    // 1.
    for (int i = 0; i < N; i++)
        s.insert(arr[i]);

    int longestStreak = 1;
    for (int i = 0; i < N; i++)
    {
        int num = arr[i];
        // 2.
        if (!s.count(num - 1))
        {
            int curNum = num;
            int curStreak = 1;

            while (s.count(curNum + 1))
            {
                curNum += 1;
                curStreak += 1;
            }
            longestStreak = max(longestStreak, curStreak);
        }
    }
    return longestStreak;
}