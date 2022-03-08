#include<iostream>
using namespace std;

string countandsay(int n)
{
    if(n==1) return "1";
    if(n==2)   return "11";
    string s="11";
    for(int i=3;i<=n;i++)
    {
        string temp="";
        int count=1;
        s+="$";

        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=s[i-1])
            {
                temp+=to_string(count);
                temp+=s[i-1];
                count=1;


            }
            else
              count++;

        }
        s=temp;
    }
    return s;
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<countandsay(n)<<endl;
}