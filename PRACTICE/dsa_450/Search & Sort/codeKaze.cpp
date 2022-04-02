#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int r,c;
        cin>>r>>c;
        cout<<"Case #"<<i<<":"<<endl;
        
        

        //1st row //..+-+-
        cout<<"..+";
        for(int j=0;j<c-1;j++)
          cout<<"-+";
        cout<<endl; 

        //2nd row //..|.|.
        cout<<"..|";
        for(int j=0;j<c-1;j++)
          cout<<".|";
        cout<<endl; 

        //for the remaining rows

        for(int j=0;j<r-1;j++)
        {
            for(int k=0;k<c;k++)
            
                cout<<"+-";
            cout<<"+"<<endl;
            for(int k=0;k<c;k++)
            
                cout<<"|.";
            cout<<"|"<<endl;

        } 

        //last closing row
        for(int k=0;k<c;k++)
            
                cout<<"+-";
            cout<<"+"<<endl;
    }
}