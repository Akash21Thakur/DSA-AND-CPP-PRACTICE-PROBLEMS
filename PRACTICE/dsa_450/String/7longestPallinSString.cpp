#include <iostream>
#include <cstring>

using namespace std;
// ..BRUTE FORCE o(N^3)
// find all the substring and check for each (O(n^2)*O(n))

// METHOD-2  dp based  time: O(n^2) , Space: O(n^2)
// make 2d array...
// preprocess for len=1 & 2
// for the remaining
//  ---> s[start]==s[end]  (boundary element should be equal)
//  ---> dp[start+1][end-1]==true (non-boundary element should be equal)

// row=start, column=end
void LPS(string s)
{
    int n = s.length();

    int dp[n][n] = {0};

    // diagonal elements true
    // len=1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    int start = 0, maxlen = 1;
    // for len=2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            if (maxlen == 1)
            {
                maxlen = 2;
                start = i;
            }
        }
    }

    //   for len>=3
    for (int k = 3; k <= n; k++)
    {
        // i=start,j=end,k=substring_length

        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] and s[i] == s[j])
            {
                dp[i][j] = 1;
                if (k > maxlen)
                {
                    maxlen = k;
                    start = i;
                }
            }
        }
    }
    cout << "LONGEST PALLINDROMIC SUBSTRING : ";
    cout << s.substr(start, maxlen);
}

//method-3 time:O(n^2) space:O(1)

// int LPS2(string str){
// int n = str.size(); // calculating size of string
//     if (n < 2)
//         return n; // if string is empty then size will be 0.
//                   // if n==1 then, answer will be 1(single
//                   // character will always palindrome)
 
//     int maxLength = 1,start=0;
//     int low, high;
//     for (int i = 0; i < n; i++) {
//         low = i - 1;
//         high = i + 1;
//         while ( high < n && str[high] == str[i]) //increment 'high'                                  
//             high++;
       
//         while ( low >= 0 && str[low] == str[i]) // decrement 'low'                   
//             low--;
       
//         while (low >= 0 && high < n && str[low] == str[high]){
//               low--;
//             high++;
//         }
 
//         int length = high - low - 1;
//         if (maxLength < length) {
//             maxLength = length;
//               start=low+1;
//         }
//     }
     
//       cout<<"Longest palindrome substring is: ";
//       cout<<str.substr(start,maxLength);
//     return maxLength;
//   }  

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;

    LPS(s);
}