#include<iostream>
#include<set>
// #include<utility>
using namespace std;

class akash{
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2)
    {
        return p1.second<p2.second;
    }
};

int main()
{
    pair<string,int> p1 =make_pair("A",10);
    pair<string,int> p2 =make_pair("D",40);
    pair<string,int> p3 =make_pair("C",300);
    pair<string,int> p4 =make_pair("B",45);

    multiset<pair<string,int>,akash> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;

}