
#include <bits/stdc++.h>
using namespace std;


// GFG AND CODE LIBRARY
// DFS AND RECURSION

class Solution{
    public:
    int helper(string target,int i,int j,vector<vector<char> > &mat, int row,int col,int idx)
   {
       int count = 0;
       if(i >= 0 && i <= row && j >= 0 && j <= col && target[idx] == mat[i][j])
       {
           char temp = target[idx];
           idx += 1;
           
           mat[i][j] = 0;
           if(target[idx] == 0)
               count = 1;
           else
           {
               count += helper(target,i,j+1,mat,row,col,idx);
               count += helper(target,i,j-1,mat,row,col,idx);
               count += helper(target,i+1,j,mat,row,col,idx);
               count += helper(target,i-1,j,mat,row,col,idx);
           }
           
           mat[i][j] = temp;
       }
       return count;
   }
   int findOccurrence(vector<vector<char> > &mat, string target){
       int count = 0;
       for(int i=0;i<mat.size();i++)
       {
           for(int j=0;j<mat[0].size();j++)
           {
               count += helper(target,i,j,mat,mat.size()-1,mat[0].size()-1,0);
           }
       }
       return count;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends