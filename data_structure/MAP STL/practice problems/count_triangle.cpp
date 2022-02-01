#include<iostream>
#include<unordered_map>

using namespace std;

int countTriangle(int a[][2],int n)
{
    unordered_map<int,int> x;
    unordered_map<int,int> y;
//maintain the count of x,y points
    for(int i=0;i<n;i++)
    {
        x[a[i][0]]++;
        y[a[i][1]]++;
    }

    int count=0;

    for(int i=0;i<n;i++)
    {
        if(x[a[i][0]]>=1 and y[a[i][1]]>=1)
          count+=((x[a[i][0]]-1)*(y[a[i][1]]-1));
    }
    return count;

}

int main()
{
    int a[][2]={ { 1, 2 }, { 2, 1 },{ 2, 2 }, { 2, 3 },{ 3, 2 } };
    cout<<countTriangle(a,5)<<endl;
}