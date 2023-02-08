#include <iostream>
using namespace std;

// POLYMORPHISM

// compile-time
// METHOD-OVERLOADING--> Function with same name but having different parameter and return type

// runtime
// METHOD-OVERRIDING--> Function with same name and parameter but one is in the super class and the other in the subclass

class Base
{
    int a, b, c;

public:
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }

    int sum(int a, int b)
    {
        return a + b;
    }

    void print()
    {
        cout << "Base Class " << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived Class " << endl;
    }
};

int main()
{
    Base obj;

    // overloading
    cout << "Sum-1 : " << obj.sum(1, 2, 3) << endl;
    cout << "Sum-2 : " << obj.sum(1, 2) << endl;

    // overriding
    Derived obj1;
    obj1.print();
}