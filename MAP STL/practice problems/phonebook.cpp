#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,vector<string>> um;
    um["Rahul"].push_back("81022");
    um["Rahul"].push_back("81023");
    um["Rahul"].push_back("81024");
    um["Rahul"].push_back("81025");
    um["Rahul"].push_back("81026");
    um["Rahul"].push_back("81027");
    um["Akash"].push_back("51027");
    um["Akash"].push_back("61027");
    um["Akash"].push_back("71027");
    um["Akash"].push_back("91027");

    for(auto x:um)
    {
        cout<<x.first<<" => ";
        for(string s:x.second)
          cout<<s<<" ";
          cout<<endl;
    }

    if(um.count("Akash"))
    {
        for(string s:um["Akash"])
          cout<<s<<" ";
    }
    else{
        cout<<"Not Found !"<<endl;
    }


}