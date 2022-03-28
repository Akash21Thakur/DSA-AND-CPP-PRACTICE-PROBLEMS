#include<iostream>
#include<cstring>
using namespace std;

int countOperations(string s1,string s2)
{
    if(s1.length()!=s2.length())   return -1;
    int a[256];
    memset(a,0,sizeof(a));
    int n=s1.length();

    //count the freq of character of s1
    for(int i=0;i<n;i++)
        a[s1[i]]++;

    //match the freq with s2  
    for(int i=0;i<n;i++)
        a[s2[i]]--;

    //check if match found...if all counts==0
    for(int i=0;i<256;i++)
       if(a[i])   return -1;
       
    int i=n-1,j=n-1,ans=0;

    while(i>=0)
    {
        while(s1[i]!=s2[j] and i>=0)
        {
            i--;
            ans++;

        }

        if(i>=0)
        {
            i--;j--;
        }


    }       


return ans;
}

int main()
{
    string s1,s2;
    cout<<"Enter String-1 : ";
    cin>>s1;
    cout<<"Enter String-2 : ";
    cin>>s2;

    int ans=countOperations(s1,s2);
    if(ans==-1)
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
    else{
        cout<<"Operation Required : "<<ans;
    }
}