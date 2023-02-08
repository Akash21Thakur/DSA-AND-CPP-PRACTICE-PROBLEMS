#include <iostream>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "class A " << endl;
    }
};

class B : public A
{
public:
    void print()
    {
        cout << "class B" << endl;
    }
};

class C : public B
{
public:
    void print()
    {
        cout << "class C" << endl;
    }
};

int main()
{
    A obj1;
    obj1.print();

    B obj2;
    obj2.print();

    C obj3;
    obj3.print();
}