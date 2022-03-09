#include<iostream>
using namespace std;
//similar to longest common subsequence of two string...to be solved later

int longRepeatSubseq(string s)
{
    int n=s.length();
    int dp[n+1][n+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //base case
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }

            //if we continue from the previous string and add characters
            //keeping up the condition
            else if(s[i-1]==s[j-1] and i!=j)  
              dp[i][j]=dp[i-1][j-1]+1;

              //new string...beginning
            else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
        }
    }
    //will store the maximum
    return dp[n][n];

}
int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Max Length : "<<longRepeatSubseq(s);

}