#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    int a[26]={0};
	    for(int i=0;i<n;i++)
	    {
	        a[s[i]-'a']++;
	    }
	    int maxi=*max_element(a,a+26);
	    int ans=ceil(n/2.0);
	    if(maxi>ans)  cout<<0<<endl;
	    else   cout<<1<<endl;
	}
}