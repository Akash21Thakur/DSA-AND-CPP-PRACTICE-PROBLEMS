#include<iostream>
#include<map>
using namespace std;

void findDup(string s)
{
    map<char,int> m;
    int n=s.length();

    for(int i=0;i<n;i++)
      m[s[i]]++;

    for(auto it: m)
      if(it.second>1)
        cout<<it.first<<" count : "<<it.second<<endl;  


}

int main()
{
    cout<<"Enter the string : ";
    string str;
    cin>>str;

    findDup(str);
}