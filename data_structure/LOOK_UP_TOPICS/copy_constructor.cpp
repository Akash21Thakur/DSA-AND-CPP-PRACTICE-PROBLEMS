#include <iostream>
using namespace std;

class Demo
{
    int x;

public:
    Demo()
    {
        cout << "Default Constructor " << endl;
    }

    Demo(int d)
    {
        this->x = d;
        cout << "Parametrized Constructor " << endl;
    }

    Demo(Demo &t)
    {
        x = t.x;
        cout << "Copy Constructor" << endl;
    }

    void display()
    {
        cout << x << endl;
    }
};

int main()
{
    Demo obj;
    Demo obj1(2);
    Demo obj2(obj1);

    obj1.display();
    obj2.display();
}