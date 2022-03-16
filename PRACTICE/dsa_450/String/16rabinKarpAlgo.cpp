#include <iostream>
#include<cstring>
using namespace std;

// abdul barri video...best explanation
//sol: gfg

#define d 256   // total numbers of possible symbol
#define mod 101 // a prime   number

void rabinKarpAlgo(string s, string pattern)
{
    int n = s.length();
    int m = pattern.length();

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for string
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    //h: d^(m-1)
    //will be used will substracting the first charcter contribution in hash value
    for (i = 0; i < m - 1; i++)
        h = (h * d) % mod;
    
    // calulate hash value for pattern and first substring
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % mod;
        t = (d * t + s[i]) % mod;
    }

    // slide the window for all possible substring s
    for (i = 0; i <= n - m; i++)
    {
        //  check if hash value matches...
        //  then check the characters one by one...print the idx if pattern found
        if (p == t)
        {
            bool flag = true;
            // matching each character
            for (j = 0; j < m; j++)
            {
                if (s[i + j] != pattern[j])
                  break;
            }
            if (j == m)
                cout << "Pattern found at : " << i << endl;
        }

        // claculate for next Substring
        if (i < n - m)
        {
            t = (d * (t - s[i] * h) + s[i + m]) % mod;
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + mod);
        }
    }
}

int main()
{
    string s, pattern;
    cout << "Enter the string : ";
    getline(cin,s);
    cout << "Enter text : ";
    getline(cin,pattern);

    rabinKarpAlgo(s, pattern);
}