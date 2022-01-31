#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   int count=0, ans=n-1;
	    for(int i=1;i<=sqrt(ans);i++)
	    {
	        if(ans%i==0)
	        {
	            if(ans/i==i) {
	                count++;cout<<i<<" ";
	            }
	            else {count+=2;cout<<i<<" "<<n/i<<" ";}
	        }
	    }
	    cout<<count<<endl;
	    
	}
}
