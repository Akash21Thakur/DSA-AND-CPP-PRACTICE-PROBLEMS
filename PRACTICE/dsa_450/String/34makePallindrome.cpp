#include<iostream>
using namespace std;

//naive and easy to implement...gfg

bool isPallin(string s)
{
    int i=0,j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
           return false;
         i++,j--;
    }
    return true;
}

int makePallin(string s)
{
    int ans=0;
    int n=s.length()-1;
    while(n--)
    {
        if(isPallin(s))
        {
            return ans;
        }
        s.erase(s.end()-1);
        ans++;
    }
  return ans;
}

int main()
{
    string s;
    cout<<"String : ";
    cin>>s;
    cout<<"Operation : "<<makePallin(s);
}



//HARD AND DIDN'T UNDERSTOOD

//method-2...kmp and lps
// C++ program for getting minimum character to be
// added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;

// returns vector lps for given string str
vector<int> computeLPSArray(string str)
{
	int M = str.length();
	vector<int> lps(M);

	int len = 0;
	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M)
	{
		if (str[i] == str[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (str[i] != str[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0)
			{
				len = lps[len-1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str)
{
	string revStr = str;
	reverse(revStr.begin(), revStr.end());

	// Get concatenation of string, special character
	// and reverse string
	string concat = str + "$" + revStr;

	// Get LPS array of this concatenated string
	vector<int> lps = computeLPSArray(concat);

	// By subtracting last entry of lps vector from
	// string length, we will get our result
	return (str.length() - lps.back());
}

// Driver program to test above functions
int main()
{
	string str = "AACECAAAA";
	cout << getMinCharToAddedToMakeStringPalin(str);
	return 0;
}
