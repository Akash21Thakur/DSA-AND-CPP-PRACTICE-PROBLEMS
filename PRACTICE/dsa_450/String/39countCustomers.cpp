#include<iostream>
#include<vector>
using namespace std;


//TRY YOURSELF TYPE PROBLEM

int countCustomer(int n,string s)
{
    int count=0,ans=0;
    vector<int> v(26,0);

    for(int i=0;i<s.length();i++)
    {
        char ch=s[i]-'A';
        if(v[ch]==0)
        {
            if(count<n)
            {
                count++;
                v[ch]=1;
            }
            else{
                ans++;
                v[ch]=2;
            }
        }
        else
        {
            if(v[ch]==1)
            {
                count--;
                v[ch]=0;
            }
            
        }
        // cout<<count<<" ";

    }
    cout<<endl;
    return ans;
}


int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    string s;
    cout<<"Enter String : ";
    cin>>s;
    cout<<"Lost Customers : "<<countCustomer(n,s)<<endl;

}