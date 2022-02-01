#include<iostream>
#include<set>
using namespace std;

//SET GIVES UNIQUE AND SORTED ORDER ELEMENTS
int main()
{
    int a[]={8,40,50,2,50,100,3,6,6,70,100,3,99};
    int n=sizeof(a)/sizeof(int);
    set<int> s;
    for(int i=0;i<n;i++)
      s.insert(a[i]);
    
    s.erase(100);//directly remove element from set

    auto i=s.find(40);//finds the element
    s.erase(i);//remove by index
    
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
       cout<<*it<<" ";

}