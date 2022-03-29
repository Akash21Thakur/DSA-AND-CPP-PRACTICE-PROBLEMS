// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
// class Solution
#include<map>
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        if(s1.length()!=s2.length())
           return 0;
        int n=s1.length();
        map<char,char> mp1,mp2; //map s1 to s2 and vice-versa
        
        int i=0;
        while(i<n)
        {
            if((mp1.find(s1[i])!=mp1.end() and mp1[s1[i]]!=s2[i]) or
                     (mp2.find(s2[i])!=mp2.end() and mp2[s2[i]]!=s1[i]))
                break;
            mp1[s1[i]]=s2[i];
            mp2[s2[i]]=s1[i];
            i++;    
               
        }
        
        
        
        if(i<n)  return 0;
           
         return 1;  
          
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends