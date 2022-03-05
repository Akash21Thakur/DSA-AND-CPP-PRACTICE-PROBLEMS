#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
        int last=s.size()-1;
        int start=0;
        
        while(start<=last)
           swap(s[start++],s[last--]);
                
        
    }

int main()
{
    int n;
    cin>>n;
    vector<char> s;
    
    for(int i=0;i<n;i++)
      cout<<s[i]<<" ";

}