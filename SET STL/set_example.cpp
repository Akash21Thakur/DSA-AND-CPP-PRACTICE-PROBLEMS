#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<pair<int,int>> s;
    // s.insert(make_pair(10,5));
    s.insert(make_pair(20,5));
    s.insert(make_pair(10,15));
    s.insert(make_pair(30,5));
    s.insert(make_pair(20,55));
    s.insert(make_pair(40,20));
    s.insert(make_pair(30,15));
    s.insert(make_pair(50,5));
    s.insert(make_pair(10,5));


    auto it=s.lower_bound(make_pair(5,3));//gives the immediate next greater value
    //in case first number matches,checks for the second value
    //similarly works the lower_bound method
    cout<<it->first<<" "<<endl;

    // for(auto x:s)
    //   cout<<x.first<<" "<<x.second<<endl;
}