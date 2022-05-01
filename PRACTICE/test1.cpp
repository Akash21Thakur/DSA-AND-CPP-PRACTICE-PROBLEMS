#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cout << "Case #" << j << ": ";
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
           cin>>a[i];
        int i=0,k=n-1,mini;
        if(a[i]<a[k]) 
        {
            mini=a[i];
            i++;
        }  
        else
          mini=a[j--];
          int count=0;
        while(i<=j)
        {
            if(a[i]>=mini or a[j]>=mini)
            {
                if(a[i]>=mini and a[i]<=a[j])
                {
                    mini=a[i];
                    i++;
                }
                else
                {
                    mini=a[j];
                    j--;
                }
                count++;

            }
            else
              break;
        }
        cout<<count<<endl;  
    }
}