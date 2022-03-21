// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    //cube surrounding the current pos
    int x[8]={-1,-1,-1,0,0,1,1,1};
    int y[8]={-1,0,1,-1,1,-1,0,1};
    
    bool helper(vector<vector<char>> &grid,string word,int i,int j,int row,int col)
    {
        
        int len=word.length();
        for(int temp=0;temp<8;temp++)
        {
           int  new_row=i+x[temp];
           int  new_col=j+y[temp];
            int k;
            for(k=1;k<len;k++)//check from words[1] in all the possible direction
            {
                if(new_row<0 or new_row>=row or new_col<0 or new_col>=col)
                   break;
                
                if(grid[new_row][new_col]!=word[k])   
                   break;
                   
                new_row+=x[temp],new_col+=y[temp];   
                   
            }
            
            if(k==len)//word match found
              return true;
        }
        return false;
    }
    
    
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    int k=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            //if the first word matches we check for the rest
	            //if returned true...inde is added to the answer
	            if(grid[i][j]==word[0] and helper(grid,word,i,j,n,m))
	            {
	                ans.push_back({i,j});
	               
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends