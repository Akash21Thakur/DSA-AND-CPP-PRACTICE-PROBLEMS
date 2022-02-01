#include<iostream>
#include<set>
using namespace std;

typedef multiset<int>:: iterator It;

int main()
{
    multiset<int> m; //stores all occurence of element in sorted order
    int a[]={10,20,45,40,10,20,20,60,90};
    int n=sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++)
      m.insert(a[i]); 

    cout<<m.count(20)<<endl;  //gives the count of value
    // m.erase(10);
    
    //iterate
    for(int i:m)
      cout<<i <<" "; 

    cout<<endl;

    pair<It,It> p=m.equal_range(20);//returns the first and last occurence of the value's iterator

    for(It i=p.first;i!=p.second;i++)
       cout<<*i<<" ";  

    cout<<endl;
    for(It i=m.lower_bound(20);i!=m.upper_bound(85);i++)//prints elements in the range of lower and upper bound
       cout<<*i <<" " ; 

}

