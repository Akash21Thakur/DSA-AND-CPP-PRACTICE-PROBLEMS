#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<char,int> mp;

void badMatchTable(string pat)
{
    int n=pat.length();
    int value;
    for(int i=0;i<n-1;i++)
    {
        value=n-i-1;
        mp[pat[i]]=value;

    }
    mp[pat[n-1]]=n;
}
 
int boyerMoore(string text,string pattern)
{
    // 1. Construst Bad match table
    badMatchTable(pattern);
    // 2. Comarision
    int n=text.length();
    int m=pattern.length();

    int i=m-1,j,temp;

    while(i<n)
    {
        j=m-1,temp=i;
        while(text[temp]==pattern[j] and j>=0)
        {
            temp--;
            j--;
        }
        if(j<0)
          return temp+1;

        if(mp[text[i]]!=0)  i+=mp[text[i]];
        else  i+=m;  

    }
    return -1;
}

int main()
{
    string text,pattern;
    cout<<"Enter the text : ";
    getline(cin,text);
    cout<<"Enter the Pattern : ";
    getline(cin,pattern);

    int ans=boyerMoore(text,pattern);
    if(ans!=-1) cout<<"Pattern Found at index : "<<ans<<endl;
    else
    cout<<"Not Found"<<endl;


}