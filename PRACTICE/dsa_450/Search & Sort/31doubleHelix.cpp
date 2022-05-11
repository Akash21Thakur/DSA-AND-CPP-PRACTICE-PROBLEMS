#include<iostream>
#include<vector>
using namespace std;

//ref :  code library
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
          break;
        else
        {
            vector<int> v1(n);
            for(int i=0;i<n;i++)
               cin>>v1[i];
            int m;
            cin>>m;
            vector<int> v2(m);
            for(int i=0;i<m;i++)
                cin>>v2[i];

            int ans=0,i=0,j=0,s1=0,s2=0;

            while(i<n and j<m)
            {
                if(v1[i]<v2[j])
                  s1+=v1[i++];
                else if(v2[j]<v1[i])
                  s2+=v2[j++];
                else{
                    //bridge found
                    ans+= v1[i] + max(s1,s2);
                    s1=s2=0;
                    i++;
                    j++;
                }    
            } 
            
            //v1 still has element left
            while(i<n)
               s1+=v1[i++];
               
            //v2 still has element left
            while(j<m)
               s2+=v2[j++];
               
            //choose the path giving max. sum
            //it is for the elements after the last brigde...or for the ones with no bridge
             ans+=max(s1,s2);

             cout<<ans<<endl;           
        }  
    }
}