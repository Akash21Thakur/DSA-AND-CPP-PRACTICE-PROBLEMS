#include<iostream>
#include<unordered_map>
#include<map>
#include<cstring>
using namespace std;

int main()
{
    unordered_map<string,int> m;          // SIMILAR TO MAP IN TERMS OF IMPLEMENTATION
    // map<string,int> m; 
    m.insert(make_pair("Apple",50));
    m.insert(make_pair("Mango",100));

    pair<string,int> p;
    p.first="Grapes";
    p.second=150;

    m.insert(p);

    m["Orange"]=120;
    m["Guava"]=60;
    for(auto pq:m)
      cout<<pq.first<<" : "<<pq.second<<endl;

      m.insert(make_pair("Banana",80));

    if(m.count("Banana"))
      cout<<"Price of Banana is : "<<m["Banana"]<<endl; 
    else
      cout<<"Not found !"<<endl;   

    m.erase("Orange");
    auto it=m.find("Orange");
    if(it!=m.end())
      cout<<"Orange : "<<m["Orange"]<<endl;
    else
      cout<<"Not Found !"<<endl;    

}