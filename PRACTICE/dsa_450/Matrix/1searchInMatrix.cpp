#include <iostream>
#include <vector>
using namespace std;

// Striver for detailed understanding

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        // method-1
        //  less optimal

        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n and j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target) // column --
                j--;
            else // row ++
                i++;
        }
        return false;

        // METHOD-2  MOST OPTIMAL   binary-search

        //         if(matrix.size()==0)  return false;
        //         int m=matrix.size(),n=matrix[0].size();
        //         int start=0,end=m*n-1;
        //          while(start<=end){
        //              // int mid=start+(end-start)/2;
        //              int mid=(start+end)/2;
        // int x=mid/n;   //row
        //              int y=mid%n;    //column

        //              if(matrix[x][y]==target)   return true;

        //              if(matrix[x][y]>target)   end=mid-1;
        //              else
        //                  start=mid+1;
        //          }
        //         return false;
    }
};