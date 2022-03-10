//find maximum length substr with equal number of 1-0
#include<iostream>
using namespace std;

int maxSubStr(string s)
{
    int zero=-1,one=-1;
    int n=s.length();
    while(n--)
    {
        if(s[n-1]=='0')  zero++;
        else   one++;
    }

    if(one==-1 or zero==-1)   return -1;

    return (min(one,zero)+1);

}

int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<"Maximum count : "<<maxSubStr(s);
}