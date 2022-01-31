#include<iostream>
using namespace std;

class Fun{
    public:

    void operator()(){
        cout<<"Overloading ()"<<endl;
    }

    void operator()(string s)
    {
        cout<<"Hey there !"<<s<<endl;
    }
};


int main()
{
    Fun f;
    f();//seems like a function call but...f is object for class Fun
    
    f("akash");

}