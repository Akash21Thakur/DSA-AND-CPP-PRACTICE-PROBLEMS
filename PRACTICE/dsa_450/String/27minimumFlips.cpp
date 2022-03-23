// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    //check for both the possibility...and return the minimum flip one
    int zero_one=0,one_zero=0;
    for(int i=0;i<S.length();i++)
    {
        
        if(i%2==0)
        {
            if(S[i]!='0')
               zero_one++;
            else
               one_zero++;
        }
        else
        {
            if(S[i]!='1')
               zero_one++;
            else
               one_zero++;
        }
    }
    return min(zero_one,one_zero);
}