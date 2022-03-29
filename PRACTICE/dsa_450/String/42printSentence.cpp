#include<iostream>
using namespace std;

//DFS and simple recursion
// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/


#define r 3
#define c 3

void helper(string a[r][c],int m,int n,string output[r])
{
    output[m]=a[m][n];

    if(m==r-1)
    {
        for(int i=0;i<r;i++)
           cout<<output[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i=0;i<c;i++)
       if(a[m+1][i]!="")
          helper(a,m+1,i,output);

}

void print(string a[r][c])
{
    string output[r];

    for(int i=0;i<c;i++)
       if(a[0][i] !="")
          helper(a,0,i,output);
}

int main()
{
   string a[r][c]={{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
   print(a);                      
}