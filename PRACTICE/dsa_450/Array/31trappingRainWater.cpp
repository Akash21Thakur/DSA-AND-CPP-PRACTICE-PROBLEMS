#include <bits/stdc++.h>
using namespace std;

// prob_link :  https://leetcode.com/problems/trapping-rain-water/submissions/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        /*method-1   time : O(n) , space : O(n)
      int n=height.size();
      int leftmax[n],rightmax[n];
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i]);
            rightmax[n-i-1]=max(rightmax[n-i],height[n-i-1]);
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
          int  water= min(leftmax[i],rightmax[i])-height[i];
            if(water>0)  ans+=water;
        }
        return ans;
        */

        // METHOD-2    TIME : O(n) , SPACE : O(1)
        int n = height.size();
        int left = 0, right = n - 1;                // for traversal
        int lmax = height[0], rmax = height[n - 1]; // values maximum to current position left/right

        int ans = 0;
        while (left <= right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > lmax)
                {
                    lmax = height[left]; // update new max
                }
                else
                    ans += lmax - height[left];
                left++;
            }
            else
            {
                if (height[right] > rmax)
                {
                    rmax = height[right];
                }
                else
                    ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};