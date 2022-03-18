#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

// for detailed explanation --> CODE LIBRARY

int countTheReversal (string s)
{
    int n=s.length();
    if(n&1)  return -1; //odd length means balancing is not possible
    stack<char> st;
    int open=0,close=0;
    //similar to balanced parenthesis
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        if(ch=='{')
        {
            st.push(ch);
            open++;
            
        }
        else if(ch=='}' and !st.empty())
        {
            st.pop();
            open--;
        }
        else
          close++;
        
    }
    int ans=0;
    ans+=ceil(open/2.0);
    ans+=ceil(close/2.0);
    
    return ans;
}

int main()
{
    string s;
    cout<<"Enter '{' formed braces string : ";
    cin>>s;

    cout<<countTheReversal(s)<<endl; 
}