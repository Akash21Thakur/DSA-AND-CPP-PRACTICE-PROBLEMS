#include <bits/stdc++.h>
using namespace std;

//VVVI QUESTION
//ABDUL BARI...GFG
// https://www.geeksforgeeks.org/longest-prefix-also-suffix/

class Solution{
  public:		
	int lps(string s) {
	    int n=s.length();
	    int lps[n]; //tracks lps till i
	    lps[0]=0;   //obvious
	    int i=1,len=0;
	    
	    while(i<n)
	    {
	        if(s[i]==s[len])  //when string matches the pattern
	        {
	            len++;
	            lps[i]=len;
	            i++;
	        }
	        else  //match not found
	        {
	            if(len==0)  //when pattern itr reaches start , check for next charact next character in the string s
	            {
	                lps[i]=0;
	                i++;
	            }
	            else //match has been found till the prev index
	            {
	                len=lps[len-1];
	            }
	        }
	    }
	    return len;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends